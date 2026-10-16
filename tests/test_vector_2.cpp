#include "catch2/catch.hpp"
#include "array/vector.hpp"



TEST_CASE("Copy constructor and assignment")
{
     dsac::array::Vector<int> v1;
     v1.push_back(1);
     v1.push_back(2);
     v1.push_back(3);
     dsac::array::Vector<int> v2(v1);
     dsac::array::Vector<int> v3;
     v3.push_back(1);
     v3.push_back(2);
     v3.push_back(3);
     v3 = v1;
     REQUIRE(v1.size() == v2.size());
     REQUIRE(v1.capacity() == v2.capacity());
     for(int k{0}; k < v1.size(); k++)
     {
        REQUIRE(v1.at(k) == v2.at(k));
        REQUIRE(v1.at(k) == v3.at(k));
     }
}

TEST_CASE("Move construcotr and assignment")
{
    dsac::array::Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    dsac::array::Vector<int> v2;
    dsac::array::Vector<int> v3;
    v3 = dsac::array::Vector<int>(3);
    v2 = std::move(v1);
    REQUIRE(v1.empty() == true);
    REQUIRE(v2.size() == 3);
    REQUIRE(v1.capacity() == 0);
    REQUIRE(v2.capacity() == 4);
    REQUIRE(v2.at(0) == 1);
    REQUIRE(v2.at(1) == 2);
    REQUIRE(v2.at(2) == 3);
    REQUIRE(v3.at(0) == 0);
    REQUIRE(v3.at(1) == 0);
    REQUIRE(v3.at(2) == 0);
}
TEST_CASE("Dereferencing")
{
    dsac::array::Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    auto itr1 = v1.begin();
    auto itr2 = v1.end();
    itr2--;
    REQUIRE(*itr1 == 1);
    REQUIRE(*itr2 == 4);

}
TEST_CASE("Incrementing")
{
    dsac::array::Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    auto itr1 = v1.begin();
    auto itr2 = v1.begin();
    REQUIRE(*itr1 == 1);
    REQUIRE(*itr2 == 1);
    itr1++;
    REQUIRE(*itr1 == 2);
    REQUIRE(*(++itr2) == 2);
    REQUIRE(*itr2 == 2);
}

TEST_CASE("Decrementing")
{
    dsac::array::Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    auto itr1 = v1.end();
    auto itr2 = v1.end();
    itr1--;
    itr2--;
    REQUIRE(*itr1 == 4);
    REQUIRE(*itr2 == 4);
    itr1--;
    auto itr3 = --itr2;
    REQUIRE(*itr1 == 3);
    REQUIRE(*itr2 == 3);
    REQUIRE(*itr3 == 3);
}

TEST_CASE("Comparing Iterators")
{
    dsac::array::Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    auto itr1 = v1.begin();
    auto itr2 = v1.end();
    itr2--;
    REQUIRE(*itr1 == 1);
    REQUIRE(*itr2 == 4);
    itr1++;
    itr2--;
    itr2--;
    REQUIRE(*itr1 == *itr2);
}

TEST_CASE("Changing elements through iterator")
{
    dsac::array::Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    auto itr1 = v1.begin();
    *itr1 = 4;
    REQUIRE(v1.at(0) == 4);
}

