
#include "catch.hpp"
#include "Optimal_BST.h"


TEST_CASE( "Test Tree" )
{
	BinaryTree<int> Node;
	Node.add(2);
	Node.add(1);
	Node.add(5);
	Node.add(5);
	Node.add(0);
	
	REQUIRE(Node.search(0));
	REQUIRE_FALSE(Node.search(7));
}

TEST_CASE( "add") {

	BinaryTree<int> tree;
	Node<int>* foundNode = nullptr;

    SECTION( "add 42" ) {
		tree.add(42);
		foundNode = tree.search(42);
		REQUIRE(foundNode);
        REQUIRE(foundNode->value == 42 );
    }

    SECTION( "add smaller to the left" ) {
		tree.add(3);
		tree.add(2);
		foundNode = tree.search(3);
		REQUIRE(foundNode);
        REQUIRE(foundNode->left->value == 2);
    }

    SECTION( "add larger to the right" ) {
		tree.add(3);
		tree.add(4);
		foundNode = tree.search(3);
		REQUIRE(foundNode);
		REQUIRE(foundNode->right->value == 4);
    }
}

TEST_CASE( "Test lookup " )
{
	BinaryTree<int> tree;

	tree.add(2);
	tree.add(1);
	tree.add(5);
	tree.add(5);
	tree.add(0);
	
	REQUIRE(tree.search(5));
	REQUIRE_FALSE(tree.search(7));
}

