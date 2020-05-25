cmake_minimum_required(VERSION 3.12)
project(Tree_algorithms)

set(CMAKE_CXX_STANDARD 17)

include_directories(includes)

set(SOURCES src/Calculator.cpp)
set(HEADERS includes/RedBlackTree.h includes/RBTreeNode.h includes/SplayTree.h includes/Calculator.h includes/AVL_Tree.h includes/Optimal_BST.h includes/Persistent_RBT.h)

set(TESTS_SOURCES unit-tests/tests-main.cpp unit-tests/tests-calculator.cpp unit-tests/catch.hpp)

add_executable(Tree_algorithms ${TESTS_SOURCES} ${SOURCES} ${HEADERS})
