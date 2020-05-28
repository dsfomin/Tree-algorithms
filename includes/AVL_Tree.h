#pragma once
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
class AVL_Node
{
public:
	AVL_Node() {
		left = nullptr;
		right = nullptr;
		height = 1;
	}
	AVL_Node(int key, AVL_Node* left = nullptr, AVL_Node* right = nullptr) {
		this->key = key;
		this->left = left;
		this->right = right;
		height = 1;
	}
	AVL_Node(AVL_Node* copy) {
		this->key = copy->key;
		this->left = copy->left;
		this->right = copy->right;
		this->height = copy->height;
	}
	
	T key;
	AVL_Node *left;
	AVL_Node *right;
	int height;
};


template <typename T>
class AVL_Tree {
public:
	AVL_Node<T>* root;

	AVL_Tree() {}
	AVL_Tree(AVL_Node<T>* root) {
		if (root != nullptr) {
			this->root->key = root->key;
			this->root->left = root->left;
			this->root->right = root->right;
			this->root->height = root->height;
		}
	}
	//! Inserts the key 'x' into the tree.
	void insert(T x) { root = insert(root, x); }
	//! Removes the key 'val' into the tree.
	void remove(T x) { root = deleteNode(root, x); }
	//! Prints in preorder.
	void _cout() { preOrder(root); }
private:
	//! Gets height of tree.
	int height(AVL_Node<T> *N);
	//! Balances tree.
	int getBalance(AVL_Node<T> *N);
	//! Rotates subtree to right.
	AVL_Node<T>* rightRotate(AVL_Node<T> *y);
	//! Rotates subtree to left.
	AVL_Node<T>* leftRotate(AVL_Node<T> *x);
	//! Inserts the key 'val' into the subtree.
	AVL_Node<T>* insert(AVL_Node<T>* node, T key);
	//! Returns the pointer to the node with the min key in subtree.
	AVL_Node<T>* minValueNode(AVL_Node<T>* node);
	//! Removes the key 'val' into the subtree.
	AVL_Node<T>* deleteNode(AVL_Node<T>* root, T key);
	//! Prints in preorder node 'root'.
	void preOrder(AVL_Node<T> *root);
	//! Returns the pointer to the node with the key 'key' in subtree.
	AVL_Node<T>* search(T key, AVL_Node<T>* root);
};

template <typename T>
void AVL_Tree<T>::preOrder(AVL_Node<T> *root)
{
	if (root != nullptr)
	{
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

template<typename T>
AVL_Node<T>* AVL_Tree<T>::search(T key, AVL_Node<T>* root)
{
	if (root == nullptr) return nullptr;;
	else if (key < root->key) return search(key, root->left);
	else if (key > root->key) return search(key, root->right);
	else return root;
	
}

template <typename T>
int AVL_Tree<T>::height(AVL_Node<T> *N)
{
	if (N == nullptr)return 0;
	return N->height;
}

template <typename T>
int AVL_Tree<T>::getBalance(AVL_Node<T> *N)
{
	if (N == nullptr)return 0;
	return height(N->left) - height(N->right);
}

template <typename T>
AVL_Node<T> *AVL_Tree<T>::rightRotate(AVL_Node<T> *y)
{
	AVL_Node<T> *x = y->left;
	AVL_Node<T> *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

template <typename T>
AVL_Node<T> *AVL_Tree<T>::leftRotate(AVL_Node<T> *x)
{
	AVL_Node<T> *y = x->right;
	AVL_Node<T> *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}

template <typename T>
AVL_Node<T>* AVL_Tree<T>::insert(AVL_Node<T>* node, T key)
{
	if (node == nullptr)
		return new AVL_Node<T>(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;

	node->height = 1 + max(height(node->left),
		height(node->right));

	int balance = getBalance(node);

	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

template <typename T>
AVL_Node<T> * AVL_Tree<T>::minValueNode(AVL_Node<T>* node)
{
	AVL_Node<T>* current = node;

	while (current->left != nullptr)
		current = current->left;

	return current;
}

template <typename T>
AVL_Node<T>* AVL_Tree<T>::deleteNode(AVL_Node<T>* root, T key)
{
	if (root == nullptr)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else
	{
		if ((root->left == nullptr) ||
			(root->right == nullptr))
		{
			AVL_Node<T> *temp = root->left ? root->left : root->right;

			if (temp == nullptr)
			{
				temp = root;
				root = nullptr;
			}
			else
				*root = *temp;
			free(temp);
		}
		else
		{
			AVL_Node<T>* temp = minValueNode(root->right);

			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}

	if (root == nullptr)
		return root;

	root->height = 1 + max(height(root->left), height(root->right));

	int balance = getBalance(root);

	if (balance > 1 &&
		getBalance(root->left) >= 0)
		return rightRotate(root);

	if (balance > 1 &&
		getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 &&
		getBalance(root->right) <= 0)
		return leftRotate(root);

	if (balance < -1 &&
		getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}