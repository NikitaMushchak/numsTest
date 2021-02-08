#include "whattotest.cpp"
#include <bitset>
#include "gtest/gtest.h"
#include <future>
#include <stack>
//#include "H:\googletest-release-1.10.0\googletest\include\gtest\gtest.h"


TEST(isPrimeTest, Zero) {
    ASSERT_TRUE(!isPrime(0));
    ASSERT_TRUE(!isPrime(-0));
   
}

TEST(isPrimeTest, PositiveNos) {
    ASSERT_TRUE(!isPrime(1));
    ASSERT_TRUE(isPrime(2));
    ASSERT_TRUE(isPrime(3));
    ASSERT_TRUE(!isPrime(4));
    ASSERT_TRUE(isPrime(5));
    ASSERT_TRUE(!isPrime(6));
    ASSERT_TRUE(isPrime(7));
    ASSERT_TRUE(!isPrime(8));
    ASSERT_TRUE(!isPrime(9));
    ASSERT_TRUE(isPrime(109));
    ASSERT_TRUE(!isPrime(111));
}


int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
