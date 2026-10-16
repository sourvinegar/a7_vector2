#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "array/vector.hpp"

TEST_CASE("default contructor")
{
    dsac::array::Vector<int> v1;
    REQUIRE(v1.capacity() == 0);
    REQUIRE(v1.size() == 0);
    REQUIRE(v1.empty() == true);
}

TEST_CASE("contructor with parameters")
{
    dsac::array::Vector<int> v1(3);

    REQUIRE(v1.capacity() == 3);
    REQUIRE(v1.empty() == false);
    REQUIRE(v1.size() == 3);
}


TEST_CASE("operator []")
{
    dsac::array::Vector<int> v1;
    v1.push_back(4);
    v1.push_back(5);
    REQUIRE(v1[0] == 4);
    REQUIRE(v1[1] == 5);
}


TEST_CASE("operator at")
{
    dsac::array::Vector<int> v1;
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(5);

    REQUIRE(v1.at(1) == 5);
    REQUIRE(v1.at(2) == 5);
    REQUIRE_THROWS(v1.at(3));
}

TEST_CASE("operator front")
{
    dsac::array::Vector<int> v1;
     v1.push_back(4);
     v1.push_back(5);
     v1.push_back(6);
     //{4,5,6}

    REQUIRE(v1.front() == 4);
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.push_back(5);
    //{5}
    REQUIRE(v1.front() == 5);

}

TEST_CASE("operator back")
{
    dsac::array::Vector<int> v1;
     v1.push_back(4);
     v1.push_back(5);
     v1.push_back(6);
    // {4,5,6}
    REQUIRE(v1.back() == 6);
    v1.pop_back();
    // {4, 5}
    v1.pop_back();
    // {4}  
    REQUIRE(v1.back() == 4);

}

TEST_CASE("push_back and pop_back")
{
    dsac::array::Vector<int> v1;
     v1.push_back(4);
     REQUIRE(v1.at(0) == 4);
     v1.push_back(5);
     REQUIRE(v1.at(1) == 5);
     v1.push_back(6);
     REQUIRE(v1.at(2) == 6);

    v1.pop_back();
    REQUIRE(v1.at(1) == 5);
    v1.pop_back();
    REQUIRE(v1.at(0) == 4);
    v1.pop_back();
    REQUIRE(v1.empty() == true);
}

TEST_CASE("insert")
{
     dsac::array::Vector<int> v1(3);
     //{0,0,0}
     REQUIRE(v1.at(1) == 0);
     v1.insert(1, 24);
     REQUIRE(v1.at(1) == 24);
}

TEST_CASE("erase")
{
     dsac::array::Vector<int> v1;
     v1.push_back(4);
     v1.push_back(5);
     v1.push_back(6);
     v1.push_back(7);
    // {4,5,6,7}
     v1.erase(2);
    // {4,5,7}
     REQUIRE(v1.at(2) == 7);
}

TEST_CASE("reserve")
{
    dsac::array::Vector<int> v1(3);
    v1.reserve(5);
    REQUIRE(v1.capacity() == 5);
}

TEST_CASE("reallocate")
{
     dsac::array::Vector<int> v1;
     v1.push_back(4);
     v1.push_back(5);
     // {4, 5}
     v1.reallocate(5);
     REQUIRE(v1.capacity() == 5);
     REQUIRE(v1.at(0) == 4);
     REQUIRE(v1.at(1) == 5);

}

TEST_CASE("shrink to fit")
{
    dsac::array::Vector<int> v1(4);
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.push_back(7);
    v1.shrink_to_fit();
    REQUIRE(v1.capacity() == 1);
}
