
#include "catch.hpp"
#include "Optimal_BST.h"


TEST_CASE( "Test Tree" )
{
	BinaryTree<int> Node;
	REQUIRE(Node.add(2) == true );
	REQUIRE(Node.add(1) == true );
	REQUIRE(Node.add(5) == true );
	REQUIRE(Node.add(5) == true );
	REQUIRE(Node.add(0) == true );
	
	REQUIRE(Node.getRoot(0) == true );
	REQUIRE(Node.getRoot(7) == false );
}

TEST_CASE( "add") {

	BinaryTree<int> Node;

    SECTION( "add 42" ) {
		Node.add(42);
        REQUIRE( to_string(Node) == "42" );
    }

    SECTION( "add smaller to the left" ) {
		Node.add(3);
		Node.add(2);
        REQUIRE( to_string(Node) == "3(2,.)" );
    }

    SECTION( "add larger to the right" ) {
		Node.add(3);
		Node.add(4);
        REQUIRE( to_string(Node) == "3(.,4)" );
    }

    SECTION( "add twice has no effect" ) {
		Node.add(3);
		Node.add(4);
		Node.add(4);
        REQUIRE( to_string(Node) == "3(.,4)" );
    }
}

TEST_CASE( "Test lookup " )
{
	BinaryTree<int> Node;
	REQUIRE(Node.add(2) == true );
	REQUIRE(Node.add(1) == true );
	REQUIRE(Node.add(5) == true );
	REQUIRE(Node.add(5) == true );
	REQUIRE(Node.add(0) == true );
	
	REQUIRE(Node.lookup(5) == 5 );
	REQUIRE(Node.lookup(7) == 0 );
}

