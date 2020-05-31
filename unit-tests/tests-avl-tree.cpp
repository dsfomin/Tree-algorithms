#include "catch.hpp"
#include "AVL_Tree.h"

TEST_CASE("Test insert one node", "[AVL_Node]")
{
  AVL_Tree<int> AVL_Node;
  AVL_Node.insert(1);
  REQUIRE(AVL_Node.height() == 1);
}

TEST_CASE("Right right case", "[AVL_Node]")
{
  AVL_Tree<int> AVL_Node;
  AVL_Node.insert(1);
  AVL_Node.insert(2);
  REQUIRE(AVL_Node.height() == 2);
  REQUIRE_FALSE(AVL_Node.search(0));
  REQUIRE(AVL_Node.search(1));
  REQUIRE(AVL_Node.search(2));
}

TEST_CASE("Left left case", "[AVL_Node]")
{
  AVL_Tree<int> AVL_Node;
  AVL_Node.insert(-1);
  AVL_Node.insert(-2);
  REQUIRE(AVL_Node.height() == 2);
  REQUIRE_FALSE(AVL_Node.search(0));
  REQUIRE(AVL_Node.search(-1));
  REQUIRE(AVL_Node.search(-2));
}

TEST_CASE("Right left case")
{
  AVL_Tree<int> AVL_Node;
  AVL_Node.insert(2);
  AVL_Node.insert(1);
  REQUIRE(AVL_Node.height() == 2);
  REQUIRE_FALSE(AVL_Node.search(0));
  REQUIRE(AVL_Node.search(2));
  REQUIRE(AVL_Node.search(1));
}

TEST_CASE("Left right case", "[AVL_Node]")
{
  AVL_Tree<int> AVL_Node;
  AVL_Node.insert(-2);
  AVL_Node.insert(-1);
  REQUIRE(AVL_Node.height() == 2);
  REQUIRE_FALSE(AVL_Node.search(0));
  REQUIRE(AVL_Node.search(-2));
  REQUIRE(AVL_Node.search(-1));
}

TEST_CASE("Find") {
    AVL_Tree<int> AVL_Node;
    AVL_Node.insert(10);
    AVL_Node.insert(-2);
    AVL_Node.insert(0);
    AVL_Node.insert(4);
    AVL_Node.insert(12);
    AVL_Node.insert(20);
    AVL_Node.insert(14);

    REQUIRE(AVL_Node.search(10));
    REQUIRE(AVL_Node.search(-2));
    REQUIRE(AVL_Node.search(0));
    REQUIRE(AVL_Node.search(4));
    REQUIRE(AVL_Node.search(4));
    REQUIRE(AVL_Node.search(12));
    REQUIRE(AVL_Node.search(20));
    REQUIRE(AVL_Node.search(14));

    REQUIRE(!AVL_Node.search(6));
    REQUIRE(!AVL_Node.search(30));
    REQUIRE(!AVL_Node.search(-20));
}

TEST_CASE("Remove") {
    AVL_Tree<int> AVL_Node;
    AVL_Node.insert(10);
    AVL_Node.insert(-2);
    AVL_Node.insert(0);
    AVL_Node.insert(4);
    AVL_Node.insert(12);
    AVL_Node.insert(20);
    AVL_Node.insert(14);

    AVL_Node.remove(4);
    REQUIRE_FALSE(AVL_Node.search(4));
    AVL_Node.remove(14);
    REQUIRE_FALSE(AVL_Node.search(14));
    AVL_Node.remove(-2);
    REQUIRE_FALSE(AVL_Node.search(-2));
}
