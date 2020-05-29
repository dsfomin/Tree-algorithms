#include "catch.hpp"
#include "SplayTree.h"


TEST_CASE("Check if splay tree works fine with integers", "[SplayTree]")
{
    SplayTree<int> splayTree;
   
    SECTION("Insertion into splay tree")
    {
        splayTree.insert(3);

        SECTION("Check splay tree")
        {
            REQUIRE(splayTree.getRoot()->key == 3);
            REQUIRE(splayTree.getRoot()->parent == nullptr);
            REQUIRE(splayTree.getRoot()->left == nullptr);
            REQUIRE(splayTree.getRoot()->right == nullptr);
        }

        splayTree.insert(1);

        SECTION("Check if element becomes new root")
        {
            REQUIRE(splayTree.getRoot()->key == 1);
        }

        splayTree.insert(2);
        splayTree.insert(6);
        splayTree.insert(5);
        splayTree.insert(4);


        SECTION("Check final state of the tree")
        {
            SECTION("Check root")
            {
                REQUIRE(splayTree.getRoot()->parent == nullptr);
                REQUIRE(splayTree.getRoot()->key == 4);
            }

            SECTION("Check right subtree")
            {
                REQUIRE(splayTree.getRoot()->right->parent == splayTree.getRoot());
                REQUIRE(splayTree.getRoot()->right->key == 5);

                REQUIRE(splayTree.getRoot()->right->right->parent == splayTree.getRoot()->right);
                REQUIRE(splayTree.getRoot()->right->right->key == 6);
            }

            SECTION("Check left subtree")
            {
                REQUIRE(splayTree.getRoot()->left->parent == splayTree.getRoot());
                REQUIRE(splayTree.getRoot()->left->key == 2);

                REQUIRE(splayTree.getRoot()->left->left->parent == splayTree.getRoot()->left);
                REQUIRE(splayTree.getRoot()->left->left->key == 1);

                REQUIRE(splayTree.getRoot()->left->right->parent == splayTree.getRoot()->left);
                REQUIRE(splayTree.getRoot()->left->right->key == 3);
            }
        }
    }


    splayTree.insert(3);
    splayTree.insert(1);
    splayTree.insert(2);
    splayTree.insert(6);
    splayTree.insert(5);
    splayTree.insert(4);

    int rootKey = splayTree.getRoot()->key;
    int rootValue = splayTree.getRoot()->value;
    int leafKey = splayTree.getRoot()->right->right->key;
    int innerNodeKey = splayTree.getRoot()->right->key;
    int absentKey = 0;

    SECTION("Searching in splay tree")
    {
        SECTION("Searching for the root")
        {
            REQUIRE(splayTree.search(rootKey)->key == rootKey);
            SECTION("Check that root")
            {
                REQUIRE(splayTree.getRoot()->key == rootKey);
            }
        }

        SECTION("Searching for leaf")
        {
            REQUIRE(splayTree.search(leafKey)->key == leafKey);

            SECTION("Check that leaf becomes new root")
            {
                REQUIRE(splayTree.getRoot()->key == leafKey);
            }
        }
    }


    SECTION("Removing from the splay tree")
    {
        SECTION("Removing the root")
        {
            splayTree.remove(rootKey);
            SECTION("Check the key has been removed")
            {
                REQUIRE(splayTree.search(rootKey) == nullptr);
            }
        }

        SECTION("Removing leaf")
        {
            splayTree.remove(leafKey);
            SECTION("Check the key has been removed")
            {
                REQUIRE(splayTree.search(leafKey) == nullptr);
            }
        }
    }
} 