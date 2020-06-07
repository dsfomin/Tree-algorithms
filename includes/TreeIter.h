#include "AVL_Tree.h"

using namespace std;

template<typename KeyType>
class AVL_Node;

template<typename KeyType>
class AVL_Tree;


template <typename KeyType, typename U>
class Iterator {
public:
	std::stack<AVL_Node<KeyType>*> stack;
	AVL_Tree<KeyType>* tree;
	virtual bool hasNext() = 0;
	virtual KeyType next() = 0;
};

template <typename KeyType, typename U>
class PreorderIterator : public Iterator<KeyType, U> {
public:
	std::stack<AVL_Node<KeyType>*> stack;
	AVL_Tree<KeyType>* tree;
	PreorderIterator(AVL_Tree<KeyType>* t) : tree(t)
	{
		if (tree->root != nullptr) stack.push(tree->root);
	}
	bool hasNext() {
		return !stack.empty();
	}
	KeyType next() {
		if (!hasNext()) cerr << "Error!" << std::endl;
		AVL_Node<KeyType> x = stack.top();
		stack.pop();
		KeyType key = x.key;
		if (x.right != nullptr) {
			stack.push(x.right);
		}
		if (x.left != nullptr) {
			stack.push(x.left);
		}
		return key;
	}
};
template <typename KeyType, typename U>
class InorderIterator : public Iterator<KeyType, U> {
public:
	std::stack<AVL_Node<KeyType>*> stack;
	AVL_Node<KeyType>* current;
	AVL_Node<KeyType>* pending;
	AVL_Node<KeyType>* root;
	InorderIterator(AVL_Tree<KeyType>* t) : root(t->root)
	{
		if (root != nullptr) {
			current = root;

			while (root) {
				stack.push(root);
				root = root->left;
			}
		}
	}
	bool hasNext() {
		return !stack.empty();
	}
	KeyType next() {
		if (!hasNext()) cerr << "Error!" << std::endl;
		pending = stack.top();
		stack.pop();
		current = pending->right;
		while (current) {
			stack.push(current);
			current = current->left;
		}
		return pending->key;
	}
};

template <typename KeyType, typename U>
class PostorderIterator : public Iterator<KeyType, U> {
public:
	std::stack<AVL_Node<KeyType>*> stack;
	AVL_Tree<KeyType>* tree;
	PostorderIterator(AVL_Tree<KeyType>* t) : tree(t)
	{
		if (tree->root != nullptr) stack.push(tree->root);
	}
	bool hasNext() {
		return !stack.empty();
	}
	KeyType next() {
		if (!hasNext()) cerr << "Error!" << std::endl;
		AVL_Node<KeyType> x = stack.top();
		stack.pop();
		KeyType key = x.key;
		if (x.left != nullptr) {
			stack.push(x.left);
		}
		if (x.right != nullptr) {
			stack.push(x.right);
		}
		return key;
	}
};