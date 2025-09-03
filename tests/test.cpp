//test cases for prime.cpp functions using Catch2
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../incl/prime.hpp"
// Testing few prime identification
TEST_CASE("Prime Identification Tests", "[isPrimeHalf][isPrimeSqrt]") {
    SECTION("isPrimeHalf") {
        REQUIRE(isPrimeHalf(2) == true);
        REQUIRE(isPrimeHalf(3) == true);
        REQUIRE(isPrimeHalf(4) == false);
        REQUIRE(isPrimeHalf(17) == true);
        REQUIRE(isPrimeHalf(18) == false);
    }
    SECTION("isPrimeSqrt") {
        REQUIRE(isPrimeSqrt(2) == true);
        REQUIRE(isPrimeSqrt(3) == true);
        REQUIRE(isPrimeSqrt(4) == false);
        REQUIRE(isPrimeSqrt(17) == true);
        REQUIRE(isPrimeSqrt(18) == false);
    }
}
//Testing composite numbers
TEST_CASE("Composite Number Tests", "[isPrimeHalf][isPrimeSqrt]") {
    SECTION("isPrimeHalf") {
        REQUIRE(isPrimeHalf(9) == false);
        REQUIRE(isPrimeHalf(15) == false);
        REQUIRE(isPrimeHalf(21) == false);
    }
    SECTION("isPrimeSqrt") {
        REQUIRE(isPrimeSqrt(9) == false);
        REQUIRE(isPrimeSqrt(15) == false);
        REQUIRE(isPrimeSqrt(21) == false);
    }
}
// test for few range of prime numbers if both methods are consistent
TEST_CASE("Range Consistency Tests", "[isPrimeHalf][isPrimeSqrt]") {
    for (int num = 1; num <= 10000; ++num) {
        REQUIRE(isPrimeHalf(num) == isPrimeSqrt(num));
    }
}
// Testing mod operation counts
TEST_CASE("Modulo Operation Count Tests", "[countModOps]") {
    long long halfOps = countModOps(isPrimeHalf, 1, 100);
    long long sqrtOps = countModOps(isPrimeSqrt, 1, 100);
    REQUIRE(halfOps > sqrtOps); // Half method should perform more modulo operations than Sqrt method
    REQUIRE(sqrtOps > 0); // Ensure some operations were counted
    //consitency already tested so no need to check the exact modulo counts because we know they count with every one
    SECTION("small numbers") {
        REQUIRE(countModOps(isPrimeHalf, 1, 10) == 9);
        REQUIRE(countModOps(isPrimeSqrt, 1, 10) == 8);
    }
}
// test edge cases
