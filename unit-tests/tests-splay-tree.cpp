#include "catch.hpp"
#include "SplayTree.h"


TEST_CASE("Check if splay tree works fine with integers", "[SplayTree]")
{
    SplayTree<int> TreeNode;
   
    SECTION("Insertion into splay tree")
    {
        TreeNode.insert(3);

        SECTION("Check splay tree")
        {
            REQUIRE(TreeNode.getRoot()->key == 3);
            REQUIRE(TreeNode.getRoot()->parent == nullptr);
            REQUIRE(TreeNode.getRoot()->left == nullptr);
            REQUIRE(TreeNode.getRoot()->right == nullptr);
        }

        TreeNode.insert(1);

        SECTION("Check if element becomes new root")
        {
            REQUIRE(TreeNode.getRoot()->key == 1);
        }

        TreeNode.insert(2);
        TreeNode.insert(6);
        TreeNode.insert(5);
        TreeNode.insert(4);


        SECTION("Check final state of the tree")
        {
            SECTION("Check root")
            {
                REQUIRE(TreeNode.getRoot()->parent == nullptr);
                REQUIRE(TreeNode.getRoot()->key == 4);
            }

            SECTION("Check right subtree")
            {
                REQUIRE(TreeNode.getRoot()->right->parent == TreeNode.getRoot());
                REQUIRE(TreeNode.getRoot()->right->key == 5);

                REQUIRE(TreeNode.getRoot()->right->right->parent == TreeNode.getRoot()->right);
                REQUIRE(TreeNode.getRoot()->right->right->key == 6);
            }

            SECTION("Check left subtree")
            {
                REQUIRE(TreeNode.getRoot()->left->parent == TreeNode.getRoot());
                REQUIRE(TreeNode.getRoot()->left->key == 3);

                REQUIRE(TreeNode.getRoot()->left->left->parent == TreeNode.getRoot()->left);
                REQUIRE(TreeNode.getRoot()->left->left->key == 2);
            }
        }
    }


    TreeNode.insert(3);
    TreeNode.insert(1);
    TreeNode.insert(2);
    TreeNode.insert(6);
    TreeNode.insert(5);
    TreeNode.insert(4);

    int rootKey = TreeNode.getRoot()->key;
    int leafKey = TreeNode.getRoot()->right->right->key;
    int innerNodeKey = TreeNode.getRoot()->right->key;
    int absentKey = 0;


    SECTION("Removing from the splay tree")
    {
        SECTION("Removing the root")
        {
            TreeNode.erase(rootKey);
            SECTION("Check the key has been removed")
            {
                REQUIRE(TreeNode.getRoot()->key != rootKey);
            }
        }

        SECTION("Removing leaf")
        {
            TreeNode.erase(leafKey);
        }
    }
} 