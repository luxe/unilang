// Should be compiled with Intel compiler and optimization flags
// -xCORE-AVX-I -O3 -ipo 
// for example: icpc -xCORE-AVX-I -O3 -ipo -g -o main main.cpp random.cpp

// BASED ON IVAN DIMKOVIC's CODE WITH LICENCE BELOW

/*****************************************************************************
    
    Super-Fast MWC1616 Pseudo-Random Number Generator 
    for Intel/AMD Processors (using SSE or SSE4 instruction set)
    Copyright (c) 2012, Ivan Dimkovic
    All rights reserved.
    Redistribution and use in source and binary forms, with or without 
    modification, are permitted provided that the following conditions are met:
    Redistributions of source code must retain the above copyright notice, 
    this list of conditions and the following disclaimer.
    
    Redistributions in binary form must reproduce the above copyright notice, 
    this list of conditions and the following disclaimer in the documentation 
    and/or other materials provided with the distribution.
    
    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
    OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

#include "code/utilities/random/rand_impls/mwc1616_v2.hpp"
#include <xmmintrin.h>
#include <emmintrin.h>
#include <smmintrin.h>
#include <cassert>
#include <iostream>
using namespace std;

Random::Random(std::vector<uint16_t> seeds) {
    if(seeds.size() == 0) {
        // Use seed based on system rand()
        seeds.resize(16);
        uint32_t *ptr = (uint32_t *)&seeds[0];
        for(unsigned int i=0; i<8; i++) ptr[i] = rand();
    }

    assert((RNDSTOREDNUMBERS%4==0) && "RNDSTOREDNUMBERS needs to be a multiple of 4.");
    
    initFastRand(seeds[0], seeds[1], 
        seeds[2], seeds[3],
        seeds[4], seeds[5],
        seeds[6], seeds[7],
        seeds[8], seeds[9],
        seeds[10], seeds[11],
        seeds[12], seeds[13],
        seeds[14], seeds[15]);
    
    m_nextFloat = RNDSTOREDNUMBERS;
    m_nextDouble = RNDSTOREDNUMBERS;
    m_nextUnsignedInt = RNDSTOREDNUMBERS;
    refillRandomDoubles();
    refillRandomFloats();
    refillRandomUnsignedInts();
}

void Random::refillRandomFloats() {
    const unsigned int randomNumbersToBeGenerated = m_nextFloat;
    // We generate 4 each time with SSE4. If we have used 4N+k numbers, we will generate 4(N+1) instead
    const unsigned int limit = randomNumbersToBeGenerated/4 + (randomNumbersToBeGenerated%4 != 0); 
    const double normalizationFactor = 1.0/4294967295.0; // UINTMAX
    
    for(unsigned int i=0; i<limit; i++) {
        generateSSE4();

        m_randomFloats[4*i+0] = (double)res[0] *normalizationFactor;
        m_randomFloats[4*i+1] = (double)res[1] *normalizationFactor;
        m_randomFloats[4*i+2] = (double)res[2] *normalizationFactor;
        m_randomFloats[4*i+3] = (double)res[3] *normalizationFactor;
    }

    m_nextFloat = 0;
}

void Random::refillRandomDoubles() {
    const unsigned int randomNumbersToBeGenerated = m_nextDouble;
    // We generate 4 each time with SSE4. If we have used 4N+k numbers, we will generate 4(N+1) instead
    const unsigned int limit = randomNumbersToBeGenerated/4 + (randomNumbersToBeGenerated%4 != 0); 
    const double normalizationFactor = 1.0/4294967295.0; // UINTMAX
    
    for(unsigned int i=0; i<limit; i++) {
        generateSSE4();

        m_randomDoubles[4*i+0] = (double)res[0] *normalizationFactor;
        m_randomDoubles[4*i+1] = (double)res[1] *normalizationFactor;
        m_randomDoubles[4*i+2] = (double)res[2] *normalizationFactor;
        m_randomDoubles[4*i+3] = (double)res[3] *normalizationFactor;
    }

    m_nextDouble = 0;
}

void Random::refillRandomUnsignedInts() {
    const unsigned int randomNumbersToBeGenerated = m_nextUnsignedInt;
    // We generate 4 each time with SSE4. If we have used 4N+k numbers, we will generate 4(N+1) instead
    const unsigned int limit = randomNumbersToBeGenerated/4 + (randomNumbersToBeGenerated%4 != 0); 
    
    for(unsigned int i=0; i<limit; i++) {
        generateSSE4();
        m_randomUnsignedInts[4*i+0] = res[0];
        m_randomUnsignedInts[4*i+1] = res[1];
        m_randomUnsignedInts[4*i+2] = res[2];
        m_randomUnsignedInts[4*i+3] = res[3];
    }

    m_nextUnsignedInt = 0;
}

void Random::initFastRand( 
    uint16_t a1, uint16_t c1,
    uint16_t b1, uint16_t d1,
    uint16_t a2, uint16_t c2,
    uint16_t b2, uint16_t d2,
    uint16_t a3, uint16_t c3,
    uint16_t b3, uint16_t d3,
    uint16_t a4, uint16_t c4,
    uint16_t b4, uint16_t d4)
{
    //
    // Initialize MWC1616 masks and multipliers
    // Default values of 18000 and 30903 used
    // for multipliers

    for(uint8_t i=0;i<4;i++) {
        mask[i]=0xFFFF;
        m1[i]=0x4650;
        m2[i]=0x78B7;
    }

    a[0]=((uint32_t )c1<<16) | a1;
    a[1]=((uint32_t )c2<<16) | a2;
    a[2]=((uint32_t )c3<<16) | a3;
    a[3]=((uint32_t )c4<<16) | a4;
    b[0]=((uint32_t )d1<<16) | b1;
    b[1]=((uint32_t )d2<<16) | b2;
    b[2]=((uint32_t )d3<<16) | b3;
    b[3]=((uint32_t )d4<<16) | b4;
}

void Random::generateSSE4() {
    __m128i a_ = _mm_load_si128((const __m128i *)a);
    __m128i b_ = _mm_load_si128((const __m128i *)b);

    const __m128i mask_ = _mm_load_si128((const __m128i *)mask);
    const __m128i m1_ = _mm_load_si128((const __m128i *)m1);
    const __m128i m2_ = _mm_load_si128((const __m128i *)m2);

    __m128i amask = _mm_and_si128(a_, mask_);
    __m128i ashift = _mm_srli_epi32(a_, 0x10);
    __m128i amul = _mm_mullo_epi32(amask, m1_);
    __m128i anew = _mm_add_epi32(amul, ashift);
    _mm_store_si128((__m128i *)a, anew);

    __m128i bmask = _mm_and_si128(b_, mask_);
    __m128i bshift = _mm_srli_epi32(b_, 0x10);
    __m128i bmul = _mm_mullo_epi32(bmask, m2_);
    __m128i bnew = _mm_add_epi32(bmul, bshift);
    _mm_store_si128((__m128i *)b, bnew);

    __m128i bmasknew = _mm_and_si128(bnew, mask_);
    __m128i ashiftnew = _mm_slli_epi32(anew, 0x10);
    __m128i newRes = _mm_add_epi32(ashiftnew, bmasknew);
    _mm_store_si128((__m128i *)res, newRes);
}