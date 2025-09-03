//prime.cpp
// TODO: Implement isPrimeHalf
#include "prime.hpp"
bool isPrimeHalf(int n, long long* modOps) {
    if(n <= 1) return false;
    // Your implementation here
    // Checks for divisibility up to n/2
    // return true if n is prime else return false
    // count modulo operations when modOps is not nullptr
    for(int i = 2; i<= n/2; i++){
        if(modOps) (*modOps)++; // Increment the counter for each modulo operation
        if(n % i == 0) return false;
    }
    return true; 
}
// TODO: Implement isPrimeSqrt
//Checks for divisibility up to square root of n
    // return true if n is prime else return false
    // Remember to count modulo operations when modOps is not nullptr
bool isPrimeSqrt(int n, long long* modOps) {
    if(n <= 1) return false;
    // Your implementation here
    for(int i = 2; i*i <= n; i++){
        if(modOps) (*modOps)++; // Increment the counter for each modulo operation
        if(n % i == 0) return false;
    }
    
    return true; // Replace with actual implementation
}
// TODO: Implement countModOps
long long countModOps(PrimeFn isPrime, int lo, int hi) {
    long long totalModOps = 0;
    for(int num = lo; num <= hi; num++){
        isPrime(num, &totalModOps);

    }
    return totalModOps; // Replace with actual count of modulo operations
}