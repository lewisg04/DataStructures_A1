#ifndef MAIN_CPP
#define MAIN_CPP
#include <iostream>
#include "../incl/prime.hpp"
int main() {
    constexpr int LO = 2, HI = 10000;

    // TODO: Count modulo operations for both algorithms
    long long halfOps = countModOps(isPrimeHalf, LO, HI);
    long long sqrtOps = countModOps(isPrimeSqrt, LO, HI);

    // TODO: Print the results
    std::cout << "Half method operations: " << halfOps << "\n";
    // Add more output as needed
    std::cout << "Sqrt method operations: " << sqrtOps << "\n";
    // TODO: Calculate and print the ratio
    double ratio = static_cast<double>(halfOps) / sqrtOps;
    std::cout << "Ratio (Half/Sqrt): " << ratio << "\n";

    return 0;
}
#endif // MAIN_CPP