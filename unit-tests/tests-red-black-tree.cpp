#include "catch.hpp"

#include "RedBlackTree.h"

TEST_CASE("creating tree")
{
	RedBlackTree<int> RBTreeNode;
	REQUIRE(RBTreeNode.getRoot() == nullptr );
}

TEST_CASE("Search")
{
	RedBlackTree<int> RBTreeNode;
	RBTreeNode.insert(2);
	RBTreeNode.insert(3);
	RBTreeNode.insert(1);
	REQUIRE(RBTreeNode.search(3) == true );
	REQUIRE(RBTreeNode.search(5) == false );
}

TEST_CASE( "Insert" ) {
    RedBlackTree<int> RBTreeNode;
    REQUIRE(RBTreeNode.getRoot() == nullptr );
	RBTreeNode.print(RBTreeNode.getRoot());
    REQUIRE(ostream.str() == "" );
	RBTreeNode.insert( 10 );
	RBTreeNode.print(RBTreeNode.getRoot());
    REQUIRE( ostream.str() == "--b10\n" );
	RBTreeNode.insert( 85 );
	RBTreeNode.print(RBTreeNode.getRoot());
	RBTreeNode.insert( 15 );
	RBTreeNode.print(RBTreeNode.getRoot());
    REQUIRE( ostream2.str() ==	  "----r85\n"
	    					 "--b15\n"
	   					 "----r10\n");
	RBTreeNode.insert( 70 );
	std::ostringstream ostream3;
	RBTreeNode.print(ostream3, RBTreeNode.getRoot());
    REQUIRE( ostream3.str() ==	 		 "----b85\n"
						 "------r70\n"
						 "--b15\n"
						 "----b10\n" );
	RBTreeNode.insert( 20 );
	std::ostringstream ostream4;
	RBTreeNode.print(ostream4, RBTreeNode.getRoot());
    REQUIRE( ostream4.str() ==	 		  	"------r85\n"
							"----b70\n"
							"------r20\n"
							"--b15\n"
							"----b10\n" );
	RBTreeNode.insert( 60 );
	std::ostringstream ostream5;
	RBTreeNode.print(ostream5, RBTreeNode.getRoot());
    REQUIRE( ostream5.str() ==	 		  	"------b85\n"
							"----r70\n"
							"--------r60\n"
							"------b20\n"
							"--b15\n"
							"----b10\n" );
	RBTreeNode.insert( 30 );
	std::ostringstream ostream6;
	RBTreeNode.print(ostream6, RBTreeNode.getRoot());
    REQUIRE( ostream6.str() ==	 		  	"------b85\n"
							"----r70\n"
							"--------r60\n"
							"------b30\n"
							"--------r20\n"
							"--b15\n"
							"----b10\n" );
	RBTreeNode.insert( 50 );
	std::ostringstream ostream7;
	RBTreeNode.print(ostream7, RBTreeNode.getRoot());
    REQUIRE( ostream7.str() ==	 		  	"------b85\n"
							"----r70\n"
							"------b60\n"
							"--------r50\n"
							"--b30\n"
							"------b20\n"
							"----r15\n"
							"------b10\n" );
	RBTreeNode.insert( 65 );
	std::ostringstream ostream8;
	RBTreeNode.print(ostream8, RBTreeNode.getRoot());
    REQUIRE( ostream8.str() ==	 		  	"------b85\n"
							"----r70\n"
							"--------r65\n"
							"------b60\n"
							"--------r50\n"
							"--b30\n"
							"------b20\n"
							"----r15\n"
							"------b10\n" );
	RBTreeNode.insert( 80 );
	std::ostringstream ostream9;
	RBTreeNode.print(ostream9, RBTreeNode.getRoot());
    REQUIRE( ostream9.str() ==	 		  	"------b85\n"
							"--------r80\n"
							"----r70\n"
							"--------r65\n"
							"------b60\n"
							"--------r50\n"
							"--b30\n"
							"------b20\n"
							"----r15\n"
							"------b10\n" );
	RBTreeNode.insert( 90 );
	std::ostringstream ostream11;
	RBTreeNode.print(ostream11, RBTreeNode.getRoot());
    REQUIRE( ostream11.str() ==	 		  	"--------r90\n"
							"------b85\n"
							"--------r80\n"
							"----r70\n"
							"--------r65\n"
							"------b60\n"
							"--------r50\n"
							"--b30\n"
							"------b20\n"
							"----r15\n"
							"------b10\n" );
	RBTreeNode.insert( 40 );
	std::ostringstream ostream12;
	RBTreeNode.print(ostream12, RBTreeNode.getRoot());
    REQUIRE( ostream12.str() ==	 		  	"--------r90\n"
							"------b85\n"
							"--------r80\n"
							"----b70\n"
							"--------b65\n"
							"------r60\n"
							"--------b50\n"
							"----------r40\n"
							"--b30\n"
							"------b20\n"
							"----b15\n"
							"------b10\n" );
	RBTreeNode.insert( 5 );
	std::ostringstream ostream13;
	RBTreeNode.print(ostream13, RBTreeNode.getRoot());
    REQUIRE( ostream13.str() ==	 		  	"--------r90\n"
							"------b85\n"
							"--------r80\n"
							"----b70\n"
							"--------b65\n"
							"------r60\n"
							"--------b50\n"
							"----------r40\n"
							"--b30\n"
							"------b20\n"
							"----b15\n"
							"------b10\n"
							"--------r5\n" );
	RBTreeNode.insert( 55 );
	std::ostringstream ostream14;
	RBTreeNode.print(ostream14, RBTreeNode.getRoot());
    REQUIRE( ostream14.str() ==	 		  	"--------r90\n"
							"------b85\n"
							"--------r80\n"
							"----b70\n"
							"--------b65\n"
							"------r60\n"
							"----------r55\n"
							"--------b50\n"
							"----------r40\n"
							"--b30\n"
							"------b20\n"
							"----b15\n"
							"------b10\n"
							"--------r5\n" );
}
TEST_CASE( "Delete" ) {
    RedBlackTree<int> RBTreeNode;
    std::ostringstream ostream;
    REQUIRE(RBTreeNode.getRoot() == nullptr );
	RBTreeNode.print(ostream, RBTreeNode.getRoot());
    REQUIRE( ostream.str() == "" );
	RBTreeNode.insert( 10 );
	RBTreeNode.print(ostream, RBTreeNode.getRoot());
    REQUIRE( ostream.str() == "--b10\n" );
    //REQUIRE( tree.size() == 1 );
	RBTreeNode.remove( 10 );
	std::ostringstream ostream1;
	RBTreeNode.print(ostream1, RBTreeNode.getRoot());
    REQUIRE( ostream1.str() == "" );
    REQUIRE(RBTreeNode.getRoot() == nullptr );
    {
        RedBlackTree<int> tree;
		RBTreeNode.insert( 2 );
		RBTreeNode.insert( 1 );
		RBTreeNode.insert( 3 );
		RBTreeNode.insert( 4 );
		RBTreeNode.insert( 5 );
        //        std::cout << tree << std::endl;
        //        std::ofstream("tmp") << tree << std::endl;
        //         b2
        //        /  \
        //       /    \
        //     b1      b4
        //            /  \
        //           /    \
        //         r3      r5
		RBTreeNode.print(ostream1, RBTreeNode.getRoot());
        REQUIRE( ostream1.str() == 	     		"------r5\n"
							"----b4\n"
							"------r3\n"
							"--b2\n"
							"----b1\n" );
        //std::cout << tree << std::endl;
		RBTreeNode.deleteRBTreeNode( 2 );
        //std::ofstream("tmp") << tree << std::endl;
    }

    {
        RedBlackTree<int> RBTreeNode;
	std::ostringstream ostream;
        SECTION( "when brother is black and his sons" ) {
        RedBlackTree<int> RBTreeNode;
		RBTreeNode.insert( 1 );
		RBTreeNode.insert( 2 );
		RBTreeNode.insert( 6 );
		RBTreeNode.insert( 8 );
		RBTreeNode.insert( 9 );
		RBTreeNode.insert( 7 );
		RBTreeNode.insert( 4 );
		RBTreeNode.insert( 4 );
		RBTreeNode.insert( 2 );
		RBTreeNode.insert( 4 );
		RBTreeNode.insert( 4 );
		RBTreeNode.deleteRBTreeNode( 4 );
		RBTreeNode.deleteRBTreeNode( 4 );
		RBTreeNode.deleteRBTreeNode( 4 );
		RBTreeNode.deleteRBTreeNode( 4 );
		RBTreeNode.deleteRBTreeNode( 8 );
		RBTreeNode.print(ostream, RBTreeNode.getRoot());
        REQUIRE( ostream.str() ==			"----b9\n"
							"------r7\n"
							"--b6\n"
							"------b2\n"
							"----r2\n"
							"------b1\n" );
		RBTreeNode.deleteRBTreeNode( 9 );
		std::ostringstream ostream1;
		RBTreeNode.print(ostream1, RBTreeNode.getRoot());
        REQUIRE( ostream1.str() ==			"----b7\n"
							"--b6\n"
							"------b2\n"
							"----r2\n"
							"------b1\n" );
        }
        SECTION( "when brother is black and his right son is red" ) {
			RBTreeNode.insert( 1 );
			RBTreeNode.insert( 2 );
			RBTreeNode.insert( 3 );
			RBTreeNode.insert( 4 );
			RBTreeNode.insert( 5 );
			RBTreeNode.insert( 6 );
			RBTreeNode.insert( 7 );
			RBTreeNode.insert( 8 );
			RBTreeNode.insert( 9 );
			RBTreeNode.insert( 10 );
			RBTreeNode.insert( 11 );
			RBTreeNode.insert( 0 );
			RBTreeNode.deleteRBTreeNode(3);
		std::ostringstream ostream10;
		RBTreeNode.print(ostream10, RBTreeNode.getRoot());
        REQUIRE( ostream10.str() ==			"----------r11\n"
							"--------b10\n"
							"----------r9\n"
							"------r8\n"
							"--------b7\n"
							"----b6\n"
							"------b5\n"
							"--b4\n"
							"------b2\n"
							"----b1\n"
							"------b0\n" );
		RBTreeNode.deleteRBTreeNode( 2 );
		std::ostringstream ostream3;
		RBTreeNode.print(ostream3, RBTreeNode.getRoot());
        REQUIRE( ostream3.str() ==			"--------r11\n"
							"------b10\n"
							"--------r9\n"
							"----b8\n"
							"------b7\n"
							"--b6\n"
							"------b5\n"
							"----b4\n"
							"------b1\n"
							"--------r0\n" );
        }
        SECTION( "when brother is red" ) {
			RBTreeNode.insert( 1 );
			RBTreeNode.insert( 2 );
			RBTreeNode.insert( 3 );
			RBTreeNode.insert( 4 );
			RBTreeNode.insert( 5 );
			RBTreeNode.insert( 6 );
			RBTreeNode.insert( 7 );
			RBTreeNode.insert( 8 );
			RBTreeNode.insert( 9 );
			RBTreeNode.insert( 10 );
			RBTreeNode.insert( 11 );
			RBTreeNode.insert( 0 );
			RBTreeNode.deleteRBTreeNode( 3 );
			RBTreeNode.insert( 5 );
			RBTreeNode.insert( 5 );
			RBTreeNode.insert( 5 );
			RBTreeNode.insert( 5 );
			RBTreeNode.insert( 5 );
		std::ostringstream ostream66;
		RBTreeNode.print(ostream66, RBTreeNode.getRoot());
        REQUIRE( ostream66.str() ==			"----------r11\n"
							"--------b10\n"
							"----------r9\n"
							"------b8\n"
							"--------b7\n"
							"----r6\n"
							"------------r5\n"
							"----------b5\n"
							"--------r5\n"
							"----------b5\n"
							"------b5\n"
							"--------b5\n"
							"--b4\n"
							"------b2\n"
							"----b1\n"
							"------b0\n" );
		RBTreeNode.deleteRBTreeNode( 2 );
		std::ostringstream ostream2;
		RBTreeNode.print(ostream2, RBTreeNode.getRoot());
        REQUIRE( ostream2.str() ==			"--------r11\n"
							"------b10\n"
							"--------r9\n"
							"----b8\n"
							"------b7\n"
							"--b6\n"
							"----------r5\n"
							"--------b5\n"
							"------b5\n"
							"--------b5\n"
							"----r5\n"
							"--------b5\n"
							"------b4\n"
							"--------b1\n"
							"----------r0\n" );
        }
    }
}