//https://github.com/andeplane/MWC1616-PRNG-CPP

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

#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define RNDSTOREDNUMBERS 1000

class Random {
private:
    uint32_t a[4];
    uint32_t b[4];
    uint32_t mask[4];
    uint32_t m1[4];
    uint32_t m2[4];
    uint32_t res[4]; // 4 UINTS are stored after a generateSSE4() call
    float m_randomFloats[RNDSTOREDNUMBERS]; 
    float m_randomDoubles[RNDSTOREDNUMBERS];
    unsigned int m_randomUnsignedInts[RNDSTOREDNUMBERS];    
    unsigned int m_nextFloat;
    unsigned int m_nextDouble;
    unsigned int m_nextUnsignedInt;
    
    void initFastRand( 
        uint16_t a1, uint16_t c1,
        uint16_t b1, uint16_t d1,
        uint16_t a2, uint16_t c2,
        uint16_t b2, uint16_t d2,
        uint16_t a3, uint16_t c3,
        uint16_t b3, uint16_t d3,
        uint16_t a4, uint16_t c4,
        uint16_t b4, uint16_t d4);

    void generateSSE4();
public:
    Random(std::vector<unsigned short> seed = {});
    void refillRandomFloats();
    void refillRandomDoubles();
    void refillRandomUnsignedInts();
    float nextFloat() { return m_randomFloats[m_nextFloat++]; }
    float nextDouble() { return m_randomDoubles[m_nextDouble++]; }
    unsigned int nextUnsignedInt() { return m_randomUnsignedInts[m_nextUnsignedInt++]; }
    unsigned int nextUnsignedInt(const unsigned int maxValue) { return (m_randomUnsignedInts[m_nextUnsignedInt++] % (maxValue+1)); }
    bool nextBool() { return nextUnsignedInt(1); }
};