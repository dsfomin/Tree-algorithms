
#include "catch.hpp"
#include "Optimal_BST.h"


TEST_CASE( "Test Tree" )
{
	Optimal_BST<int> BST;
	REQUIRE( BST.insert(2) == true );
	REQUIRE( BST.insert(1) == true );
	REQUIRE( BST.insert(5) == true );
	REQUIRE( BST.insert(5) == true );
	REQUIRE( BST.insert(0) == true );
	
	REQUIRE( BST.contains(0) == true );
	REQUIRE( BST.contains(7) == false );
}

TEST_CASE( "Insert") {

    Optimal_BST<int> BST;

    SECTION( "Insert 42" ) {
        BST.insert(42);
        REQUIRE( to_string(BST) == "42" );
    }

    SECTION( "Insert smaller to the left" ) {
        BST.insert(3);
        BST.insert(2);
        REQUIRE( to_string(BST) == "3(2,.)" );
    }

    SECTION( "Insert larger to the right" ) {
        BST.insert(3);
        BST.insert(4);
        REQUIRE( to_string(BST) == "3(.,4)" );
    }

    SECTION( "Insert twice has no effect" ) {
        BST.insert(3);
        BST.insert(4);
        BST.insert(4);
        REQUIRE( to_string(BST) == "3(.,4)" );
    }
}

TEST_CASE( "Test find " )
{
	Optimal_BST<int> BST;
	REQUIRE( BST.insert(2) == true );
	REQUIRE( BST.insert(1) == true );
	REQUIRE( BST.insert(5) == true );
	REQUIRE( BST.insert(5) == true );
	REQUIRE( BST.insert(0) == true );
	
	REQUIRE( BST.contains(5) == true );
	REQUIRE( BST.contains(7) == false );
	
	REQUIRE( BST.find(5) == 5 );
	REQUIRE( BST.find(7) == 0 );
}

TEST_CASE( "Test Remove " )
{
	Optimal_BST<int> BST;
	REQUIRE( BST.height() == 0 );
	
	REQUIRE( BST.insert(2) == true );
	REQUIRE( BST.insert(1) == true );
	REQUIRE( BST.insert(5) == true );
	
	REQUIRE( BST.height() == 2 );
	
	REQUIRE( BST.remove(5) == 5 );
	
}
