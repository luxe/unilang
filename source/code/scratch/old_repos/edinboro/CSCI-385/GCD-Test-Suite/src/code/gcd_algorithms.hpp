#pragma once
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <boost/math/common_factor_rt.hpp>

//a namespace to hold various GCD algorithms.  I was thinking about making the namespace
//a non-constructable class because some algorithms use sub-functions which should not
//be accessible anywhere except the function that calls it.  However, there is a low chance of
//name clashing.  Perhaps if there was risk, we should just put sub-functions into another namespace..
//NOTE: look up later, "does inlining actually do anything now-adays?"
namespace GCD{
	
	//Euclidean algorithms
	template <typename IntegerType> IntegerType Euclid_Recursive(IntegerType a, IntegerType b);
	template <typename IntegerType> IntegerType Euclid_Iterative(IntegerType a, IntegerType b);
	template <typename IntegerType> IntegerType Euclid_Unrolled(IntegerType a, IntegerType b);
	template <typename IntegerType> IntegerType inline Euclid_Bit(IntegerType a, IntegerType b);
	
	//Binary algorithms
	template <typename IntegerType> IntegerType Binary_Recursive(IntegerType a, IntegerType b);
	template <typename IntegerType> IntegerType Binary_Iterative(IntegerType a, IntegerType b);
	template <typename IntegerType> IntegerType Binary_Iterative_V2(IntegerType a, IntegerType b);
	
	//Counting Trailing Zeros algorithm
	template <typename IntegerType> IntegerType CTZ(IntegerType a, IntegerType b);
	
	//Brute Force algorithms
	template <typename IntegerType> IntegerType Brute_Force(IntegerType a, IntegerType b);
	
	//Human algorithm
	template <typename IntegerType> IntegerType Factor(IntegerType a, IntegerType b);
	
	//Boost implementation (looks similar to Euclid_Unrolled)
	template <typename IntegerType> inline IntegerType Boost(IntegerType a, IntegerType b);
	
	//utility functions
	template <typename IntegerType> void Sieve(std::vector<IntegerType> & primes, IntegerType n);
	template <typename IntegerType> void Factor(IntegerType n, std::vector<IntegerType> & factors, const std::vector<IntegerType> & primes);
	template <typename IntegerType> void Common_Factors(const std::vector<IntegerType> & A, const std::vector<IntegerType> & B, std::vector<IntegerType> & common);
	template <typename IntegerType> IntegerType School(IntegerType a, IntegerType b, const std::vector<IntegerType> & primes);
	template <typename IntegerType> IntegerType Count_Trailing_Zeros(IntegerType n);

};

//Euclidean algorithms
template <typename IntegerType> IntegerType GCD::Euclid_Recursive(IntegerType a, IntegerType b){
    if (b==0) {
       return a;
    } else  {
       return Euclid_Recursive(b, a%b);
    }
}
template <typename IntegerType> IntegerType GCD::Euclid_Iterative(IntegerType a, IntegerType b){
	IntegerType c;
	while (b != 0){
		c = b;
		b = a%b;
		a = c;
	}
	return a;
}
template <typename IntegerType> IntegerType GCD::Euclid_Unrolled(IntegerType a, IntegerType b){
	
	while (b != 0){
		
		a = a%b;
		if(a==0){return b;}
		
		b = b%a;
		if(b==0){return a;}
	}
	
	return a;
}
template <typename IntegerType> inline IntegerType GCD::Euclid_Bit(IntegerType a, IntegerType b){
	while(b) b ^= a ^= b ^= a %= b;
	return a;
}

//Binary algorithms
template <typename IntegerType> IntegerType GCD::Binary_Recursive(IntegerType a, IntegerType b){
	
    if (a == b){return a;}
    if (a == 0){return b;}
    if (b == 0){return a;}
 
    if (~a & 1) {
        if (b & 1){
			return Binary_Recursive(a >> 1, b);
		}
        else {
			return Binary_Recursive(a >> 1, b >> 1) << 1;
		}
    }
 
    if (~b & 1){
		return Binary_Recursive(a, b >> 1);
	}
	
    if (a > b){
		return Binary_Recursive((a - b) >> 1, b);
	}
 
    return Binary_Recursive((b - a) >> 1, a);
}
template <typename IntegerType> IntegerType GCD::Binary_Iterative(IntegerType a, IntegerType b){

	//if (a == 0 && b == 0){return 0;} //convention-- *NEVERMIND already covered
	if (a == 0){ return b;}
	if (b == 0){ return a;}
	
	IntegerType c;
	for (c = 0; ((a | b) & 1) == 0; ++c) {
		a >>= 1;
		b >>= 1;
	}
	
	while ((a & 1) == 0){
		a >>= 1;
	}
	
	do {
		
		while ((b & 1) == 0){
			b >>= 1;
		}
	
		if (a > b) {
			IntegerType d = b; b = a; a = d;} //inline swap
		b = b - a;
		} while (b != 0);
	
	return a << c;
}
template <typename IntegerType> IntegerType GCD::Binary_Iterative_V2(IntegerType a, IntegerType b){
	
	IntegerType c = 0;
	
	while ( a && b && a!=b ) {
		bool ea = !(a & 1);
		bool eb = !(b & 1);
		
		if ( ea && eb ) {
			++c;
			a >>= 1;
			b >>= 1;
		}
		else if ( ea && !eb ) a >>= 1;
		else if ( !ea && eb ) b >>= 1;
		else if ( a>=b ) a = (a-b)>>1;
		else {
		IntegerType tmp = a;
		a = (b-a)>>1;
		b = tmp;
		}
	}
 
	return !a? b<<c : a<<c;
}

//Counting Trailing Zeros
template <typename IntegerType> IntegerType GCD::CTZ(IntegerType a, IntegerType b){
    
	if (a == 0){return b;}
    if (b == 0){return a;}
 
    IntegerType c = Count_Trailing_Zeros(a|b);
 
    a >>= Count_Trailing_Zeros(a);
 
    while (true){
        b >>= Count_Trailing_Zeros(b);
        if (a == b){break;}
        if (a > b){IntegerType d = b; b = a; a = d;} //inline swap
        if (a == 1){break;}
        b -= a;
    }
 
    return a << c;
}
	
//Brute Force algorithms
template <typename IntegerType> IntegerType GCD::Brute_Force(IntegerType a, IntegerType b){
	
    IntegerType c = std::min(a,b);
	if (c == 0){return std::max(a,b);} //<- fix a floating point error when a number is zero
    while (a%c != 0 or b%c !=0) {
       --c;
    }

    return c;
}
	
//human algorithm
template <typename IntegerType> IntegerType GCD::Factor(IntegerType a, IntegerType b){
    IntegerType g;
	if (a == 0 && b ==0){return 0;}
    std::vector<IntegerType> primeList;
    Sieve(primeList, std::max(a,b));
    return School(a,b,primeList);
}

//Boost implementation (looks similar to Euclid_Unrolled)
template <typename IntegerType> inline IntegerType GCD::Boost(IntegerType a, IntegerType b){
	return boost::math::gcd(a,b);
}

//utility functions
template <typename IntegerType> void GCD::Sieve(std::vector<IntegerType> & primes, IntegerType n){
    using namespace std;
	IntegerType i,j;
    vector<bool> A;

    primes.erase(primes.begin(), primes.end());

    for(i=0;i<=n;i++) {
       A.push_back(true);
    }

    for(i=2;i<=sqrt(n);i++) {
       if(A[i]) {
          primes.push_back(i);
          for(j=i*i;j<=n;j+= i) {
	     A[j] = false;
	  }
       }
    }

    for(j=i;j<=n;j++) {
        if(A[j]) {
	   primes.push_back(j);
	}
    }

    return;
}
template <typename IntegerType> void GCD::Factor(IntegerType n, std::vector<IntegerType> & factors, const std::vector<IntegerType> & primes){
    IntegerType i;
    IntegerType num;

    factors.erase(factors.begin(), factors.end());


    i = 0;
    num = n;

    while(num > 1) {
       if (num%primes[i] == 0) {
           factors.push_back(primes[i]);
	   num = num/primes[i];
       } else {
          i++;
       }
    }



    return;
}
template <typename IntegerType> void GCD::Common_Factors(const std::vector<IntegerType> & A, const std::vector<IntegerType> & B, std::vector<IntegerType> & common){

     IntegerType i,j;

     common.erase(common.begin(),common.end());

     i = 0;
     j = 0;
     while (i < A.size() and j < B.size()) {
        if (A[i] == B[j]) {
	   // same, common, push it and move both
           common.push_back(A[i]);
	   i++;
	   j++;
	} else if (A[i] > B[j]) {
	   // A is too big, so bump B;
	   j++;
	} else {
	   i++;
	}
     }

     return;
}
template <typename IntegerType> IntegerType GCD::School(IntegerType a, IntegerType b, const std::vector<IntegerType> & primes){
	using namespace std;
	vector<IntegerType> aFactors, bFactors, common;
    IntegerType gcd=1;
    IntegerType i;

    Factor(a, aFactors,primes);
    Factor(b, bFactors,primes);
    Common_Factors(aFactors, bFactors, common);

    for(i=0;i<common.size();i++) {
      gcd *= common[i];
    }

    return gcd;

}
template <typename IntegerType> IntegerType GCD::Count_Trailing_Zeros(IntegerType n){
   
	if (n == 0) {
        return -1;
    }
    IntegerType count = 0;
    while (n % 2 == 0) {
        count++;
        n >>= 1;
    }
    
    return count;
}
