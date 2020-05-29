#include "catch.hpp"
#include <AVL_Tree.h>

TEST_CASE("Single node")
{
  AVL<int> a(0);
  REQUIRE(a.size()==1);
  REQUIRE(a.height()==0);
}


TEST_CASE("Test insert one node", "[avl]")
{
  AVL<int> a(0);
  a.insert(1);
  REQUIRE(a.size()==2);
  REQUIRE(a.height()==1);
}

TEST_CASE("Right right case", "[avl]")
{
  AVL<int> a(0);
  a.insert(1);
  a.insert(2);
  REQUIRE(a.size() == 3);
  REQUIRE(a.height() == 1);
  REQUIRE(a.contain(0));
  REQUIRE(a.contain(1));
  REQUIRE(a.contain(2));
}

TEST_CASE("Left left case", "[avl]")
{
  AVL<int> a(0);
  a.insert(-1);
  a.insert(-2);
  REQUIRE(a.size() == 3);
  REQUIRE(a.height() == 1);
  REQUIRE(a.contain(0));
  REQUIRE(a.contain(-1));
  REQUIRE(a.contain(-2));
}

TEST_CASE("Right left case")
{
  AVL<int> a(0);
  a.insert(2);
  a.insert(1);
  REQUIRE(a.size() == 3);
  REQUIRE(a.height() == 1);
  REQUIRE(a.contain(0));
  REQUIRE(a.contain(2));
  REQUIRE(a.contain(1));
}

TEST_CASE("Left right case", "[avl]")
{
  AVL<int> a(0);
  a.insert(-2);
  a.insert(-1);
  REQUIRE(a.size() == 3);
  REQUIRE(a.height() == 1);
  REQUIRE(a.contain(0));
  REQUIRE(a.contain(-2));
  REQUIRE(a.contain(-1));
}

TEST_CASE("Find") {
    AvlTree<int, int> avl;
    avl.insert(10, 20);
    avl.insert(-2, 12);
    avl.insert(0, 4);
    avl.insert(4, 8);
    avl.insert(12, 104);
    avl.insert(20, 43);
    avl.insert(14, 45);

    REQUIRE(avl.find(10));
    REQUIRE(*avl.find(10) == 20);
    REQUIRE(avl.find(-2));
    REQUIRE(*avl.find(-2) == 12);
    REQUIRE(avl.find(0));
    REQUIRE(*avl.find(0) == 4);
    REQUIRE(avl.find(4));
    REQUIRE(*avl.find(4) == 8);
    REQUIRE(avl.find(4));
    REQUIRE(*avl.find(4) == 8);
    REQUIRE(avl.find(12));
    REQUIRE(*avl.find(12) == 104);
    REQUIRE(avl.find(20));
    REQUIRE(*avl.find(20) == 43);
    REQUIRE(avl.find(14));
    REQUIRE(*avl.find(14) == 45);

    REQUIRE(!avl.find(6));
    REQUIRE(!avl.find(30));
    REQUIRE(!avl.find(-20));
}

TEST_CASE("Remove") {
    AvlTree<int, int> avl;
    avl.insert(10, 8);
    avl.insert(-2, 7);
    avl.insert(0, 5);
    avl.insert(4, 10);
    avl.insert(12, 9);
    avl.insert(20, 12);
    avl.insert(14, 15);

    REQUIRE(avl.remove(4) == true);
    REQUIRE(!avl.find(4));
    REQUIRE(avl.remove(14) == true);
    REQUIRE(avl.remove(-2) == true);
    REQUIRE(avl.remove(-2) == false);
}
