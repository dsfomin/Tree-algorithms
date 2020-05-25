#include "RBTreeNode.h"
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
class PersistentRBTree
{
private:
	RBTreeNode<T>* root;

	void fixup(RBTreeNode<T>* z);
	void rotateLeft(RBTreeNode<T>* x);
	void rotateRight(RBTreeNode<T>* y);

	//! Prints the tree according to the inorder traversal.
	void print(const RBTreeNode<T>* tree, std::ostream& out);

	std::vector<RBTreeNode<T>*> version;
public:
	PersistentRBTree();
	~PersistentRBTree();
	PersistentRBTree(const PersistentRBTree &rbt);

	//! Inserts the key 'key' into the tree.
	void insert(T key);
	//! Delete the 'node' in the tree. 
	void deleteRBTreeNode(RBTreeNode<T>* node);
	//! Returns the pointer to the node with the key 'key'.
	RBTreeNode<T>* search(T key);
	//! Returns the pointer to the root.
	RBTreeNode<T>* getRoot();
	//! Set root pointer
	void setRoot(RBTreeNode<T>* new_root);
	//! Prints the tree according to the inorder traversal.
	void print(std::ostream& out = std::cout);
	//! Deletes (free the memory) all nodes.
	void clear();

	RBTreeNode<T>* getVersion(unsigned int index);
};

template <typename T>
inline void PersistentRBTree<T>::fixup(RBTreeNode<T>* z)
{
	if (!z) {
		throw std::invalid_argument("The argument z is nullptr.");
	}
	while (z->parent && z->parent->color == COLOR_RED) {
		if (z->parent == z->parent->parent->left) {
			RBTreeNode<T>* y = z->parent->parent->right;
			if (y && y->color == COLOR_RED) {
				z->parent->color = COLOR_BLACK;
				y->color = COLOR_BLACK;
				z->parent->parent->color = COLOR_RED;
				z = z->parent->parent;
			}
			else {
				if (z == z->parent->right) {
					z = z->parent;
					rotateLeft(z);
				}
				z->parent->color = COLOR_BLACK;
				z->parent->parent->color = COLOR_RED;
				rotateRight(z->parent->parent);
			}
		}
		else {
			RBTreeNode<T>* y = z->parent->parent->left;
			if (y && y->color == COLOR_RED) {
				z->parent->color = COLOR_BLACK;
				y->color = COLOR_BLACK;
				z->parent->parent->color = COLOR_RED;
				z = z->parent->parent;
			}
			else {
				if (z == z->parent->left) {
					z = z->parent;
					rotateRight(z);
				}
				z->parent->color = COLOR_BLACK;
				z->parent->parent->color = COLOR_RED;
				rotateLeft(z->parent->parent);
			}
		}
	}
	this->root->color = COLOR_BLACK;
}

template<typename T>
inline void PersistentRBTree<T>::rotateLeft(RBTreeNode<T>* x)
{
	if (!x || !x->right) {
		return;
	}

	RBTreeNode<T>* y = x->right;
	x->right = y->left;
	if (y->left) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (!x->parent) {
		this->root = y;
	}
	else if (x == x->parent->left) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

template<typename T>
inline void PersistentRBTree<T>::rotateRight(RBTreeNode<T>* y)
{
	if (!y || !y->left) {
		return;
	}

	RBTreeNode<T>* x = y->left;
	y->left = x->right;
	if (x->right) {
		x->right->parent = y;
	}
	x->parent = y->parent;
	if (!y->parent) {
		this->root = x;
	}
	else if (y == y->parent->right) {
		y->parent->right = x;
	}
	else {
		y->parent->left = x;
	}
	x->right = y;
	y->parent = x;
}

template<typename T>
inline void PersistentRBTree<T>::print(const RBTreeNode<T>* tree, std::ostream& out)
{
	if (!tree) {
		return;
	}
	print(tree->left, out);
	out << tree->key << " ";
	print(tree->right, out);
}

template<typename T>
inline void PersistentRBTree<T>::deleteRBTreeNode(RBTreeNode<T>* node)
{
	if (!node) {
		return;
	}
	deleteRBTreeNode(node->left);
	deleteRBTreeNode(node->right);
	delete node;
}

template<typename T>
inline PersistentRBTree<T>::PersistentRBTree() : root(nullptr)
{
}

template<typename T>
inline PersistentRBTree<T>::~PersistentRBTree()
{
	clear();
}

template<typename T>
inline PersistentRBTree<T>::PersistentRBTree(const PersistentRBTree & rbt)
{
	this->root = rbt->root;
}

template <class T>
RBTreeNode<T> * CopyTree(RBTreeNode<T> * node)
{
	if (node == nullptr)
		return nullptr;
	RBTreeNode<T> * newnode = new RBTreeNode<T>(node->key);
	newnode->left = CopyTree(node->left);
	newnode->right = CopyTree(node->right);
	return newnode;
}

template<typename T>
inline void PersistentRBTree<T>::insert(T key)
{
	RBTreeNode<T>* old = CopyTree(root);
	if (old) fixup(old);
	version.push_back(old);
	// The red-black tree takes ownership of z.
	RBTreeNode<T>* z = new RBTreeNode<T>(key);
	RBTreeNode<T>* x = this->root;
	RBTreeNode<T>* y = nullptr;
	while (x) {
		y = x;
		if (z->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	z->parent = y;
	if (!y) {
		this->root = z;
	}
	else if (z->key < y->key) {
		y->left = z;
	}
	else {
		y->right = z;
	}
	fixup(z);
}

/*!
 * If the node with the key 'key' exists, returns the not null pointer to that node.
 * Otherwise, returns null pointer.
 */
template<typename T>
inline RBTreeNode<T>* PersistentRBTree<T>::search(T key)
{
	RBTreeNode<T>* x = this->root;
	while (x && (key != x->key)) {
		if (key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	return x;
}

/*!
 * If the tree is not empty, returns the not null pointer to the root node.
 * Otherwise, returns null pointer.
 */
template<typename T>
inline RBTreeNode<T>* PersistentRBTree<T>::getRoot()
{
	return this->root;
}

template<typename T>
inline void PersistentRBTree<T>::setRoot(RBTreeNode<T>* new_root)
{
	root = new_root;
}

template<typename T>
inline void PersistentRBTree<T>::print(std::ostream& out)
{
	print(this->root, out);
	out << std::endl;
}

template<typename T>
inline void PersistentRBTree<T>::clear()
{
	deleteRBTreeNode(this->root);
	this->root = nullptr;
}

template<typename T>
RBTreeNode<T>* PersistentRBTree<T>::getVersion(unsigned int index)
{
	return version[index];
}
