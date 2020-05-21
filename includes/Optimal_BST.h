#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

template <typename T>
class Node{
public:
	Node<T>() : value(0), frequency(1) {};
	Node<T>(T val) : value(val), frequency(1) {};
	Node<T>(T val, unsigned int freq) : value(val), frequency(freq) {};
	Node<T>(Node<T>* n) {
		this->value = n->value;
		this->left = n->left;
		this->right = n->right;
		this->parent = n->parent;
		this->frequency = n->frequency;
	};
	T value;
	Node* right;
	Node* left;
	Node* parent;
	unsigned int frequency;
	Node<T>* clearedNode();

	void setLeft(Node<T>* l) {
		left = l;
		if (l) l->parent = this;
	}
	void setRight(Node<T>* r) {
		right = r;
		if (r) r->parent = this;
	}
	void setParent(Node<T>* p, bool left) {
		parent = p;
		if (p) {
			left ? parent->setLeft(this) : parent->setRight(this);
		}
	}
	friend bool operator <(const Node<T> &lhs, const Node<T> &rhs) {
		return lhs->value < rhs->value;
	}
};

template <typename T>
class BinaryTree
{
public:
	BinaryTree();
	void add(T val);
	void printPreOrder();
	void printInOrder();
	void printPostOrder();
	int size();
	bool lookup(T val);
	Node<T>* search(T val);
	Node<T>* optimalSearchTree();
	void setRoot(Node<T>* root) { this->root = root; }
	Node<T>* getRoot() { return root; }
private:
	Node<T>* root;
	int treeSize;
	void add(Node<T>** node, T val);
	bool lookup(Node<T>* node, T val);
	void printPreOrder(Node<T>* node);
	void printInOrder(Node<T>* node);
	void printPostOrder(Node<T>* node);
	Node<T>* search(Node<T>* node, T val);
	void allNodes(Node<T>* root);
	std::vector<Node<T>*> nodes;
	std::vector<std::vector<std::pair<int, int>>> costMatrix;
	void build(const std::vector<Node<T>*> nodes, bool left, Node<T>* parent, int begin, int end);
};

template <class T>
BinaryTree<T>::BinaryTree(){
	this->root = nullptr;
	this->treeSize = 0;
}

template <class T>
int BinaryTree<T>::size(){
	return this->treeSize;
}

template <class T>
void BinaryTree<T>::add(T val){
	add(&(this->root), val);
}

template <class T>
void BinaryTree<T>::add(Node<T>** node, T val) {

	if(*node == nullptr) {
		Node<T>* tmp = new Node<T>();
		tmp->value = val;
		tmp->left= nullptr;
		tmp->right = nullptr;
		tmp->frequency = 1;
		*node = tmp;
		
		this->treeSize++;
	}else{
		if(val > (*node)->value){
			add(&(*node)->right, val);
		}else{
			add(&(*node)->left, val);
		}
	}
}

template <class T>
void BinaryTree<T>::printInOrder(){
	printInOrder(this->root);
	std::cout << std::endl;
}

template <class T>
void BinaryTree<T>::printInOrder(Node<T>* node){
	if(node != nullptr){
		printInOrder(node->left);
		std::cout << node->value << ", ";
		printInOrder(node->right);
	}
}

template <class T>
void BinaryTree<T>::printPreOrder(){
	printPreOrder(this->root);
	std::cout << std::endl;
}

template <class T>
void BinaryTree<T>::printPreOrder(Node<T>* node){
	if(node != nullptr)	{
		std::cout << node->value << ", ";
		printInOrder(node->left);
		printInOrder(node->right);
	}
}

template <class T>
void BinaryTree<T>::printPostOrder(){
	printPostOrder(this->root);
	std::cout << std::endl;
}

template <class T>
void BinaryTree<T>::printPostOrder(Node<T>* node){
	if(node != nullptr){
		printInOrder(node->left);
		printInOrder(node->right);
		std::cout << node->value << ", ";
	}
}

template <class T>
bool BinaryTree<T>::lookup(T val){
	return lookup(this->root, val);
}

template <class T>
bool BinaryTree<T>::lookup(Node<T>* node, T val){
	if(node == nullptr){
		return false;
	}else{
		if(val == node->value){
			node->frequency++;
			return true;
		}

		if(val > node->value){
			return lookup(node->right, val);
		}else{
			return lookup(node->left, val);
		}
	}
}

template <class T>
void BinaryTree<T>::build(const std::vector<Node<T>*> nodes, bool left, Node<T>* parent, int begin, int end) {
	if (end < begin) return;
	Node<T>* temp = new Node<T>(nodes[costMatrix[begin][end].second]->value, nodes[costMatrix[begin][end].second]->frequency);
	temp->setParent(parent, left);
	build(nodes, 1, temp, begin, costMatrix[begin][end].second - 1);
	build(nodes, 0, temp, costMatrix[begin][end].second + 1, end);
}

template <class T>
int sum(const std::vector<Node<T>*>& nodes, int i, int j) {
	int s = 0;
	for (int k = i; k <= j; k++)
		s += nodes[k]->frequency;
	return s;
}


template <class T>
Node<T>* BinaryTree<T>::search(T val) {
	return search(this->root, val);
}

template <class T>
void swap(T* a, T* b)
{
	T t = *a;
	*a = *b;
	*b = t;
}

template <class T>
int partition(std::vector<Node<T>*>& vec, int low, int high)
{
	Node<T>* pivot = vec[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (vec[j]->value < pivot->value)
		{
			i++;
			swap(&vec[i], &vec[j]);
		}
	}
	swap(&vec[i + 1], &vec[high]);
	return (i + 1);
}

template <class T>
void quickSort(std::vector<Node<T>*>& vec, int low, int high)
{
	if (low < high)
	{
		int pi = partition(vec, low, high);

		quickSort(vec, low, pi - 1);
		quickSort(vec, pi + 1, high);
	}
}



template<typename T>
Node<T>* BinaryTree<T>::optimalSearchTree()
{
	nodes.clear();
	allNodes(this->root);
	quickSort(nodes, 0, nodes.size() - 1);
	int n = nodes.size();
	std::vector<std::vector<std::pair<int, int>>> cost(n, std::vector<std::pair<int, int>>(n, std::make_pair(0, 0)));

	for (int i = 0; i < n; i++) {
		cost[i][i] = std::make_pair(nodes[i]->frequency, i);
	}

	for (int L = 2; L <= n; L++) {
		for (int i = 0; i < n - L + 1; i++) {
			int j = i + L - 1;
			cost[i][j] = std::make_pair(INT_MAX, INT_MAX);

			for (int r = i; r <= j; r++) {
				int c = ((r > i) ? cost[i][r - 1].first : 0) + ((r < j) ? cost[r + 1][j].first : 0) + sum(nodes, i, j);
				if (c < cost[i][j].first) {
					cost[i][j] = std::make_pair(c, r);
				}
			}
		}
	}

	costMatrix = cost;

	Node<T>* new_root = new Node<T>(nodes[costMatrix[0][n - 1].second]);
	build(nodes, 1, new_root, 0, costMatrix[0][n - 1].second - 1);
	build(nodes, 0, new_root, costMatrix[0][n - 1].second + 1, n - 1);

	this->root = new_root;
	return new_root;
}

template <class T>
Node<T>* BinaryTree<T>::search(Node<T>* node, T val) {
	Node<T>* current = node;
	while (current) {
		if (val == current->value) {
			current->frequency++;
			return current;
		}
		else if (val < current->value) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}
	return nullptr;
}

template<typename T>
void BinaryTree<T>::allNodes(Node<T>* root)
{
	if (root) {
		nodes.push_back(root);
		allNodes(root->left);
		allNodes(root->right);
	}
}

template<typename T>
Node<T>* Node<T>::clearedNode()
{
	Node<T>* tmp;
	tmp->frequency = this->frequency;
	tmp->value = this->value;
	return tmp;
}
