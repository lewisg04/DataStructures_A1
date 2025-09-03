//test cases for prime.cpp functions using Catch2
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "prime.hpp"
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
        REQUIRE(countModOps(isPrimeHalf, 1, 10) == 10);
        REQUIRE(countModOps(isPrimeSqrt, 1, 10) == 9);
    }
}
// test edge cases
TEST_CASE("Edge Case Tests", "[isPrimeHalf][isPrimeSqrt][countModOps]") {
    SECTION("Negative and Zero"){
        REQUIRE(isPrimeHalf(-10) == false);
        REQUIRE(isPrimeSqrt(-10) == false);
        REQUIRE(isPrimeHalf(0) == false);
        REQUIRE(isPrimeSqrt(0) == false);
    }
    SECTION("One and Two"){
        REQUIRE(isPrimeHalf(1) == false);
        REQUIRE(isPrimeSqrt(1) == false);
        REQUIRE(isPrimeHalf(2) == true);
        REQUIRE(isPrimeSqrt(2) == true);
    }
    SECTION("Single Number Range"){
        REQUIRE(countModOps(isPrimeHalf, 1, 1) == 0); // 1 is not prime
        REQUIRE(countModOps(isPrimeSqrt, 1, 1) == 0);
        REQUIRE(countModOps(isPrimeHalf, 2, 2) == 0); // 2 is prime
        REQUIRE(countModOps(isPrimeSqrt, 2, 2) == 0);
        REQUIRE(countModOps(isPrimeHalf, 3, 3) == 1); // 3 is prime
        REQUIRE(countModOps(isPrimeSqrt, 3, 3) == 1);
        REQUIRE(countModOps(isPrimeHalf, 5, 5) == 1); // 5 is prime
        REQUIRE(countModOps(isPrimeSqrt, 5, 5) == 1);
        REQUIRE(countModOps(isPrimeHalf, 4, 4) == 1); // 4 is not prime
        REQUIRE(countModOps(isPrimeSqrt, 4, 4) == 1);
    }
    SECTION("two number range"){
        REQUIRE(countModOps(isPrimeHalf, 4, 5) == 2); // 4 is not prime, 5 is prime
        REQUIRE(countModOps(isPrimeSqrt, 4, 5) == 2);
        REQUIRE(countModOps(isPrimeHalf, 0,1) == 0);
        REQUIRE(countModOps(isPrimeSqrt, 0,1) == 0);
        // REQUIRE(countModOps(isPrimeHalf, 1,2) == 1);
        // REQUIRE(countModOps(isPrimeSqrt, 1,2) == 1);
    }
}

