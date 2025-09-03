//prime.cpp
// TODO: Implement isPrimeHalf
#include "prime.hpp"
bool isPrimeHalf(int n, long long* modOps) {
    // Your implementation here
    // Checks for divisibility up to n/2
    // return true if n is prime else return false
    // count modulo operations when modOps is not nullptr
        if(n <= 1) return false;
        if(n == 2) return true; // 2 is prime
        if(modOps) (*modOps)++;
        if(n % 2 == 0) { return false;} // Exclude even numbers greater than 2
        for(int i = 3; i <= n/2; i += 2){
            if(modOps) (*modOps)++; // Increment the counter for each modulo operation
            if(n % i == 0) return false;
        }
        return true; // Replace with actual implementation
}
// TODO: Implement isPrimeSqrt
//Checks for divisibility up to square root of n
    // return true if n is prime else return false
    // Remember to count modulo operations when modOps is not nullptr
bool isPrimeSqrt(int n, long long* modOps) {
    if(n <= 1) return false;
        if(n == 2) return true; // 2 is prime
        if(modOps) (*modOps)++;
        if(n % 2 == 0) { return false;}
    for(int i = 3; i*i <= n; i++){
        if(modOps) (*modOps)++; // Increment the counter for each modulo operation
        if(n % i == 0) return false;
    }
    // if(n == 2) {if(modOps) (*modOps)++;}
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