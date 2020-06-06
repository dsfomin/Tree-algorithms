#pragma once

#include "../includes/AVL_Tree.h"
#include "../includes/RedBlackTree.h"
#include "../includes/SplayTree.h"

template <typename KeyType, typename NodeType>
class TreeAdapter {
public:
	virtual void insert(KeyType key) = 0;
	virtual void erase(KeyType key) = 0;
	virtual void clear() = 0;

	virtual NodeType* search(KeyType key) = 0;
	virtual NodeType* getRoot() = 0;

};

template <typename KeyType>
class AvlTreeAdapter : public TreeAdapter<KeyType, AVL_Node<KeyType>> {
private:
	AVL_Tree<KeyType>* tree;

public:
	AvlTreeAdapter(AVL_Tree<KeyType>* tree) : tree{ tree } {}

    void insert(KeyType key) override { tree->insert(key); }
	void erase(KeyType key) override { tree->remove(key); }
	void clear() override { tree->clear(); }

	AVL_Node<KeyType>* search(KeyType key) override { return tree->search(key); }
	AVL_Node<KeyType>* getRoot() override { return tree->getRoot(); }

};

template <typename KeyType>
class RBTreeAdapter : public TreeAdapter<KeyType, RBTreeNode<KeyType>> {
private:
	RedBlackTree<KeyType>* tree;

public:
	RBTreeAdapter(RedBlackTree<KeyType>* tree) : tree{ tree } {}

	void insert(KeyType key) override { tree->insert(key); }
	void erase(KeyType key) override { tree->erase(key); }
	void clear() override { tree->clear(); }

	RBTreeNode<KeyType>* search(KeyType key) override { return tree->search(key); }
    RBTreeNode<KeyType>* getRoot() override { return tree->getRoot(); }

};

template <typename KeyType>
class SplayTreeAdapter : public TreeAdapter<KeyType, TreeNode<KeyType>> {
private:
	SplayTree<KeyType>* tree;

public:
	SplayTreeAdapter(SplayTree<KeyType>* tree) : tree{ tree } {}

	void insert(KeyType key) override { tree->insert(key); }
	void erase(KeyType key) override { tree->erase(key); }
    void clear() override { tree->clear(); }

    TreeNode<KeyType>* search(KeyType key) override { return tree->access(key); }
    TreeNode<KeyType>* getRoot() override { return tree->getRoot(); }

};
