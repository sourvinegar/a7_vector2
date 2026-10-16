#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "array/matrix.hpp"

TEST_CASE("Matrix construction")
{
    dsac::array::Matrix m1(3,3);
    for(int i{0}; i < 3; i++)
    {
        for(int j{0}; j < 3; j++)
        {
            REQUIRE(m1(i,j) == 0);
        }
    }
}

TEST_CASE("Accessing and modifying matrices")
{
dsac::array::Matrix m1(3,3);

    for(int i{0}; i < 3; i++)
    {
        for(int j{0}; j < 3; j++)
        {
            REQUIRE(m1(i,j) == 0);
            m1(i,j) = 4;
        }
    }

        for(int i{0}; i < 3; i++)
    {
        for(int j{0}; j < 3; j++)
        {
            REQUIRE(m1(i,j) == 4);
        }
    }

}


TEST_CASE("Matrix addition")
{
    dsac::array::Matrix m1(3,3);
    dsac::array::Matrix m2(3,3);
    for(int i{0}; i < 3; i++)
    {
        for(int j{0}; j < 3; j++)
        {
            m1(i,j) = 4;
            m2(i,j) = 5;
        }
    }

    auto m3 = m1 + m2;

    REQUIRE(m3(0,0) == 9);
    REQUIRE(m3(1,1) == 9);
    REQUIRE(m3(2,2) == 9);

}

TEST_CASE("Invalid dimensions or mismatch")
{
    REQUIRE_THROWS_AS(dsac::array::Matrix(-3,3), std::out_of_range);
    dsac::array::Matrix m1(3,3);
    dsac::array::Matrix m2(4,3);
    REQUIRE_THROWS_AS(m1+m2, std::out_of_range);
}