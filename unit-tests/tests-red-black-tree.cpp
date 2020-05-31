#include "catch.hpp"

#include "RedBlackTree.h"

TEST_CASE("creating tree")
{
	RedBlackTree<int> tree;
	REQUIRE_FALSE(tree.getRoot());
}

TEST_CASE("Search")
{
	RedBlackTree<int> tree;
	tree.insert(2);
	tree.insert(3);
	tree.insert(1);
	REQUIRE(tree.search(3));
	REQUIRE_FALSE(tree.search(5));
}

TEST_CASE( "Insert" ) {
    RedBlackTree<int> tree;
	RBTreeNode<int>* foundNode = nullptr;

	tree.insert(10);
	foundNode = tree.search(10);
	REQUIRE(foundNode);
	REQUIRE_FALSE(foundNode->left);
	REQUIRE_FALSE(foundNode->right);
	REQUIRE_FALSE(foundNode->parent);

	tree.insert(85);
	foundNode = tree.search(85);
	REQUIRE(foundNode);
	REQUIRE_FALSE(foundNode->left);
	REQUIRE_FALSE(foundNode->right);
	REQUIRE(foundNode->parent->key == 10);
}