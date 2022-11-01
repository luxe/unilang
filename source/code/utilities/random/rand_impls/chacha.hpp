#ifndef CHACHA_HPP_INCLUDED
#define CHACHA_HPP_INCLUDED 1

/*
 * A C++ version of ChaCha PRNG (*modified* from Orson Peters original code)
 *
 * Changes Copyright (c) 2017-18 Melissa E. O'Neill, licence as below.
 *
 * Changes compared to original 2015 version:
 *   - Some formatting fixes
 *   - Fix some signed/unsigned warnings
 *   - Place most code in a chacha_detail namespace
 *   - Rename classes to fit scheme used by other PRNGs
 *   - Support odd numbers of rounds (inspired by PractRand implementation)
 *   - Use SFNAE to Avoid errors from over-zealous matching of SeedSeq
 *   - Allow default construction (using arbitrary seed)
 *   - Contrsuctor passes args to seed using perfect forwarding rather
 *     than explicit code.
 *
 * Original version can be found at
 *     https://gist.github.com/orlp/32f5d1b631ab092608b1
 */

/*
    Copyright (c) 2015 Orson Peters <orsonpeters@gmail.com>
    
    This software is provided 'as-is', without any express or implied
    warranty. In no event will the authors be held liable for any
    damages arising from the use of this software.
    
    Permission is granted to anyone to use this software for any
    purpose, including commercial applications, and to alter it and
    redistribute it freely, subject to the following restrictions:
    
    1. The origin of this software must not be misrepresented; you
       must not claim that you wrote the original software. If you use
       this software in a product, an acknowledgment in the product
       documentation would be appreciated but is not required.
    
    2. Altered source versions must be plainly marked as such, and
       must not be misrepresented as being the original software.
    
    3. This notice may not be removed or altered from any source distribution.
*/

#include <cstdint>
#include <limits>
#include <utility>
#include <type_traits>

namespace chacha_detail {

template<unsigned int R>
class chacha_engine {
public:
    typedef uint32_t result_type;

    template<typename... Args>
    explicit chacha_engine(Args&&... args) {
    seed(std::forward<Args>(args)...);
    }

    void seed(uint64_t seedval = 0xb504f333f9de6484, uint64_t stream = 0);
    template<class Sseq> void seed(Sseq& seq,
      typename std::enable_if<
          !std::is_convertible<Sseq, result_type>::value
          && !std::is_convertible<Sseq, chacha_engine>::value,
          std::true_type>::type = {});                 

    uint32_t operator()();
    void discard(unsigned long long n);
    
    template<unsigned int R_>
    friend bool operator==(const chacha_engine<R_>& lhs,
               const chacha_engine<R_>& rhs);
    template<unsigned int R_>
    friend bool operator!=(const chacha_engine<R_>& lhs,
               const chacha_engine<R_>& rhs);

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(
    std::basic_ostream<CharT, Traits>& os, const chacha_engine<R>& rng);

    template<typename CharT, typename Traits>
    friend std::basic_istream<CharT, Traits>& operator>>(
    std::basic_istream<CharT, Traits>& is, chacha_engine<R>& rng);

    static constexpr uint32_t min() {
    return std::numeric_limits<uint32_t>::min();
    }

    static constexpr uint32_t max() {
    return std::numeric_limits<uint32_t>::max();
    }

private:
    void generate_block();
    void chacha_core();

    alignas(16) uint32_t block[16];
    uint32_t keysetup[8];
    uint64_t ctr;
};


template<unsigned int R>
inline void chacha_engine<R>::seed(uint64_t seedval, uint64_t stream) {
    ctr = 0;
    keysetup[0] = seedval & 0xffffffffu;
    keysetup[1] = seedval >> 32;
    keysetup[2] = keysetup[3] = 0xdeadbeef;      // Could use 128-bit seed.
    keysetup[4] = stream & 0xffffffffu;
    keysetup[5] = stream >> 32;
    keysetup[6] = keysetup[7] = 0xdeadbeef;      // Could use 128-bit stream.
}

template<unsigned int R>
template<class Sseq>
inline void chacha_engine<R>::seed(Sseq& seq,
      typename std::enable_if<
          !std::is_convertible<Sseq, result_type>::value
          && !std::is_convertible<Sseq, chacha_engine>::value,
          std::true_type>::type) {
    ctr = 0;
    seq.generate(keysetup, keysetup + 8);
}


template<unsigned int R>
inline uint32_t chacha_engine<R>::operator()() {
    int idx = ctr % 16;
    if (idx == 0) generate_block();
    ++ctr;

    return block[idx];
}

template<unsigned int R>
inline void chacha_engine<R>::discard(unsigned long long n) {
    int idx = ctr % 16;
    ctr += n;
    if (idx + n >= 16 && ctr % 16 != 0) generate_block();
}

template<unsigned int R>
inline void chacha_engine<R>::generate_block() {
    uint32_t constants[4] = {0x61707865, 0x3320646e, 0x79622d32, 0x6b206574};

    uint32_t input[16];
    for (int i = 0; i < 4; ++i) input[i] = constants[i];
    for (int i = 0; i < 8; ++i) input[4 + i] = keysetup[i];
    input[12] = (ctr / 16) & 0xffffffffu;
    input[13] = (ctr / 16) >> 32;
    input[14] = input[15] = 0xdeadbeef; // Could use 128-bit counter.

    for (int i = 0; i < 16; ++i) block[i] = input[i];
    chacha_core();
    for (int i = 0; i < 16; ++i) block[i] += input[i];
}

#ifdef __SSE2_DONT_USE_THIS_PATH_BECAUSE_OF_BUILD_ERROR__
#include "emmintrin.h"

// Get an efficient _mm_roti_epi32 based on enabled features.
#if !defined(__XOP__)
    #if defined(__SSSE3__)
        #include <tmmintrin.h>
        #undef _mm_roti_epi32
        #define _mm_roti_epi32(r, c) (                      \
            ((c) == 8) ?                                            \
                _mm_shuffle_epi8((r), _mm_set_epi8(14, 13, 12, 15,  \
                                                   10,  9,  8, 11,  \
                                                    6,  5,  4,  7,  \
                                                    2,  1,  0,  3)) \
            : ((c) == 16) ?                                         \
                _mm_shuffle_epi8((r), _mm_set_epi8(13, 12, 15, 14,  \
                                                    9,  8, 11, 10,  \
                                                    5,  4,  7,  6,  \
                                                    1,  0,  3,  2)) \
            : ((c) == 24) ?                                         \
                _mm_shuffle_epi8((r), _mm_set_epi8(12, 15, 14, 13,  \
                                                    8, 11, 10,  9,  \
                                                    4,  7,  6,  5,  \
                                                    0,  3,  2,  1)) \
            :                                                       \
                _mm_xor_si128(_mm_slli_epi32((r), (c)),             \
                              _mm_srli_epi32((r), 32-(c)))          \
        )
    #else
        #undef _mm_roti_epi32
        #define _mm_roti_epi32(r, c) _mm_xor_si128(_mm_slli_epi32((r), (c)), \
                                                   _mm_srli_epi32((r), 32-(c)))
    #endif
#else
    #include <xopintrin.h>
#endif
    
template<unsigned int R>
inline void chacha_engine<R>::chacha_core() {
    // ROTVn rotates the elements in the given vector n places to the left.
    #define CHACHA_ROTV1(x) _mm_shuffle_epi32((__m128i) x, 0x39)
    #define CHACHA_ROTV2(x) _mm_shuffle_epi32((__m128i) x, 0x4e)
    #define CHACHA_ROTV3(x) _mm_shuffle_epi32((__m128i) x, 0x93)

    __m128i a = _mm_load_si128((__m128i*) (block));
    __m128i b = _mm_load_si128((__m128i*) (block + 4));
    __m128i c = _mm_load_si128((__m128i*) (block + 8));
    __m128i d = _mm_load_si128((__m128i*) (block + 12));

    for (unsigned int i = 1; i < R; i += 2) {
    // a += b; d ^= a; d <<<= 16;
        a = _mm_add_epi32(a, b);
        d = _mm_xor_si128(d, a);
        d = _mm_roti_epi32(d, 16);

    // c += d; b ^= c; b <<<= 12;
        c = _mm_add_epi32(c, d);
        b = _mm_xor_si128(b, c);
        b = _mm_roti_epi32(b, 12);

    // a += b; d ^= a; d <<<= 8;
        a = _mm_add_epi32(a, b);
        d = _mm_xor_si128(d, a);
        d = _mm_roti_epi32(d, 8);

    // c += d; b ^= c; b <<<= 7;
        c = _mm_add_epi32(c, d);
        b = _mm_xor_si128(b, c);
        b = _mm_roti_epi32(b, 7);

    // pseudo-transpose A:
        b = CHACHA_ROTV1(b);
        c = CHACHA_ROTV2(c);
        d = CHACHA_ROTV3(d);

    // a += b; d ^= a; d <<<= 16;
        a = _mm_add_epi32(a, b);
        d = _mm_xor_si128(d, a);
        d = _mm_roti_epi32(d, 16);

    // c += d; b ^= c; b <<<= 12;
        c = _mm_add_epi32(c, d);
        b = _mm_xor_si128(b, c);
        b = _mm_roti_epi32(b, 12);

    // a += b; d ^= a; d <<<= 8;
        a = _mm_add_epi32(a, b);
        d = _mm_xor_si128(d, a);
        d = _mm_roti_epi32(d, 8);

    // c += d; b ^= c; b <<<= 7;
        c = _mm_add_epi32(c, d);
        b = _mm_xor_si128(b, c);
        b = _mm_roti_epi32(b, 7);

    // pseudo-transpose B:
        b = CHACHA_ROTV3(b);
        c = CHACHA_ROTV2(c);
        d = CHACHA_ROTV1(d);
    }
    if (R & 1) {
    // a += b; d ^= a; d <<<= 16;
    a = _mm_add_epi32(a, b);
    d = _mm_xor_si128(d, a);
    d = _mm_roti_epi32(d, 16);

    // c += d; b ^= c; b <<<= 12;
    c = _mm_add_epi32(c, d);
    b = _mm_xor_si128(b, c);
    b = _mm_roti_epi32(b, 12);

    // a += b; d ^= a; d <<<= 8;
    a = _mm_add_epi32(a, b);
    d = _mm_xor_si128(d, a);
    d = _mm_roti_epi32(d, 8);

    // c += d; b ^= c; b <<<= 7;
    c = _mm_add_epi32(c, d);
    b = _mm_xor_si128(b, c);
    b = _mm_roti_epi32(b, 7);

    // no transpose
    }

    _mm_store_si128((__m128i*) (block), a);
    _mm_store_si128((__m128i*) (block + 4), b);
    _mm_store_si128((__m128i*) (block + 8), c);
    _mm_store_si128((__m128i*) (block + 12), d);

    #undef CHACHA_ROTV3
    #undef CHACHA_ROTV2
    #undef CHACHA_ROTV1
}
#else
template<unsigned int R>
inline void chacha_engine<R>::chacha_core() {
    #define CHACHA_ROTL32(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

    #define CHACHA_QUARTERROUND(x, a, b, c, d) \
        x[a] = x[a] + x[b]; x[d] ^= x[a]; x[d] = CHACHA_ROTL32(x[d], 16); \
        x[c] = x[c] + x[d]; x[b] ^= x[c]; x[b] = CHACHA_ROTL32(x[b], 12); \
        x[a] = x[a] + x[b]; x[d] ^= x[a]; x[d] = CHACHA_ROTL32(x[d],  8); \
        x[c] = x[c] + x[d]; x[b] ^= x[c]; x[b] = CHACHA_ROTL32(x[b],  7)

    for (unsigned int i = 1; i < R; i += 2) {
        CHACHA_QUARTERROUND(block, 0, 4,  8, 12);
        CHACHA_QUARTERROUND(block, 1, 5,  9, 13);
        CHACHA_QUARTERROUND(block, 2, 6, 10, 14);
        CHACHA_QUARTERROUND(block, 3, 7, 11, 15);
        CHACHA_QUARTERROUND(block, 0, 5, 10, 15);
        CHACHA_QUARTERROUND(block, 1, 6, 11, 12);
        CHACHA_QUARTERROUND(block, 2, 7,  8, 13);
        CHACHA_QUARTERROUND(block, 3, 4,  9, 14);
    }
    if (R & 1) {
    CHACHA_QUARTERROUND(block, 0, 5, 10, 15);
    CHACHA_QUARTERROUND(block, 1, 6, 11, 12);
    CHACHA_QUARTERROUND(block, 2, 7,  8, 13);
    CHACHA_QUARTERROUND(block, 3, 4,  9, 14);
    }

    #undef CHACHA_QUARTERROUND
    #undef CHACHA_ROTL32
}
#endif


// Implement <random> interface.
template<unsigned int R>
inline bool operator==(const chacha_engine<R>& lhs,
               const chacha_engine<R>& rhs)
{
    for (int i = 0; i < 8; ++i) {
        if (lhs.keysetup[i] != rhs.keysetup[i]) return false;
    }

    return lhs.ctr == rhs.ctr;
}

template<unsigned int R>
inline bool operator!=(const chacha_engine<R>& lhs,
               const chacha_engine<R>& rhs)
{
    return !(lhs == rhs);
}

template<unsigned int R, typename CharT, typename Traits>
inline std::basic_ostream<CharT, Traits>& operator<<(
    std::basic_ostream<CharT, Traits>& os, const chacha_engine<R>& rng)
{
    typedef typename std::basic_ostream<CharT, Traits>::ios_base ios_base;

    // Save old state.
    auto flags = os.flags();
    auto fill = os.fill();
    
    // Set flags and fill to space.
    auto space = os.widen(' ');
    os.flags(ios_base::dec | ios_base::fixed | ios_base::left);
    os.fill(space);

    // Serialize.
    for (int i = 0; i < 8; ++i) os << rng.keysetup[i] << space;
    os << rng.ctr;

    // Sestore old state.
    os.flags(flags);
    os.fill(fill);

    return os;
}

template<unsigned int R, typename CharT, typename Traits>
inline std::basic_istream<CharT, Traits>& operator>>(
    std::basic_istream<CharT, Traits>& is, chacha_engine<R>& rng)
{
    typedef typename std::basic_istream<CharT, Traits> ::ios_base ios_base;

    // Save old flags and set ours.
    auto flags = is.flags();
    is.flags(ios_base::dec);

    // Deserialize.
    for (int i = 0; i < 8; ++i) is >> rng.keysetup[i];
    is >> rng.ctr;

    // Restore old flags.
    is.flags(flags);

    return is;
}

}

using chacha4r  = chacha_detail::chacha_engine<4>;
using chacha5r  = chacha_detail::chacha_engine<5>;
using chacha6r  = chacha_detail::chacha_engine<6>;
using chacha8r  = chacha_detail::chacha_engine<8>;
using chacha12r = chacha_detail::chacha_engine<12>;
using chacha20r = chacha_detail::chacha_engine<20>;

#endif // CHACHA_HPP_INCLUDED
