#ifndef MAIN_CPP
#define MAIN_CPP
#include <iostream>
#include "../incl/prime.hpp"
int main() {
    constexpr int LO = 2, HI = 10000;

    // TODO: Count modulo operations for both algorithms
    long long halfOps = 3/* Your code here */;
    long long sqrtOps = 2/* Your code here */;

    // TODO: Print the results
    std::cout << "Half method operations: " << halfOps << "\n";
    // Add more output as needed

    // TODO: Calculate and print the ratio
    double ratio = 1/* Your code here */;
    std::cout << "Ratio (Half/Sqrt): " << ratio << "\n";

    return 0;
}
#endif // MAIN_CPP