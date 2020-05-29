cmake_minimum_required(VERSION 3.12)
project(Tree_algorithms)

set(CMAKE_CXX_STANDARD 17)

include_directories(includes)

set(SOURCES "")

set(HEADERS
		includes/RedBlackTree.h
		includes/RBTreeNode.h
		includes/SplayTree.h
		includes/AVL_Tree.h
		includes/Optimal_BST.h
		includes/Persistent_RBT.h)

set(TESTS_SOURCES
		unit-tests/catch.hpp
		unit-tests/tests-main.cpp)

add_executable(Tree_algorithms ${TESTS_SOURCES} ${SOURCES} ${HEADERS})
