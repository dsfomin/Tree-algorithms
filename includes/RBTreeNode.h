#pragma once

#include <cstddef>

enum Color {
	COLOR_RED,
	COLOR_BLACK
};

// Red-black Tree Node
template <typename KeyType>
class RBTreeNode {
public:
	KeyType key;
	Color color;

	RBTreeNode<KeyType>* parent;
	RBTreeNode<KeyType>* left;
	RBTreeNode<KeyType>* right;

	RBTreeNode(KeyType key);
};

template <typename KeyType>
inline RBTreeNode<KeyType>::RBTreeNode(KeyType key)
	: key(key),
	color(COLOR_RED),
	parent(nullptr),
	left(nullptr),
	right(nullptr)
{

}
