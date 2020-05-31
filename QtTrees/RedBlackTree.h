#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <bits/stdc++.h>

struct RBNode {
    int key;
    int h;
    RBNode *left;
    RBNode *right;
    RBNode * parent;
    bool b;

};

class RedBlackTree{
    #define NIL &sentinel
    RBNode sentinel = {0,0,NIL,NIL,NIL,true};
    RBNode *root = NIL;

public:
    void leftTurn(RBNode *x) {
        RBNode *y = x->right;
        x->right = y->left;
        if (y->left != NIL) y->left->parent = x;
        if (y != NIL) y->parent = x->parent;
        if (x->parent) {
            if (x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
        } else {
            root = y;
        }
        y->left = x;
        if (x != NIL) x->parent = y;
    }

    void rightTurn(RBNode *x) {
        RBNode *y = x->left;
        x->left = y->right;
        if (y->right != NIL) y->right->parent = x;
        if (y != NIL) y->parent = x->parent;
        if (x->parent) {
            if (x == x->parent->right)
                x->parent->right = y;
            else
                x->parent->left = y;
        } else {
            root = y;
        }
        y->right = x;
        if (x != NIL) x->parent = y;
    }

    void afterAdd(RBNode *x) {
        while (x != root && x->parent->b == 0) {
            if (x->parent == x->parent->parent->left) {
                RBNode *y = x->parent->parent->right;
                if (y->b == 0) {
                    x->parent->b = 1;
                    y->b = 1;
                    x->parent->parent->b = 0;
                    x = x->parent->parent;
                } else {
                    if (x == x->parent->right) {
                        x = x->parent;
                        leftTurn(x);
                    }
                    x->parent->b = 1;
                    x->parent->parent->b = 0;
                    rightTurn(x->parent->parent);
                }
            } else {
                RBNode *y = x->parent->parent->left;
                if (y->b == 0) {
                    x->parent->b = 1;
                    y->b = 1;
                    x->parent->parent->b = 0;
                    x = x->parent->parent;
                } else {
                    if (x == x->parent->left) {
                        x = x->parent;
                        rightTurn(x);
                    }
                    x->parent->b = 1;
                    x->parent->parent->b = 0;
                    leftTurn(x->parent->parent);
                }
            }
        }
        root->b = 1;
    }

    RBNode *insert(int data) {
        RBNode *current, *parent, *x;
        current = root;
        parent = nullptr;
        while (current != NIL) {
            if (data == current->key) return (current);
            parent = current;
            current = data < current->key ?
                current->left : current->right;
        }
        x = new RBNode;
        x->key = data;
        x->parent = parent;
        x->left = NIL;
        x->right = NIL;
        x->b = 0;
        if(parent) {
            if(data<parent->key)
                parent->left = x;
            else
                parent->right = x;
        } else {
            root = x;
        }
        afterAdd(x);
        return(x);
    }

    void afterDrop(RBNode *x) {
        while (x != root && x->b == 1) {
            if (x == x->parent->left) {
                RBNode *w = x->parent->right;
                if (w->b == 0) {
                    w->b = 1;
                    x->parent->b = 0;
                    leftTurn (x->parent);
                    w = x->parent->right;
                }
                if (w->left->b == 1 && w->right->b == 1) {
                    w->b = 0;
                    x = x->parent;
                } else {
                    if (w->right->b == 1) {
                        w->left->b = 1;
                        w->b = 0;
                        rightTurn (w);
                        w = x->parent->right;
                    }
                    w->b = x->parent->b;
                    x->parent->b = 1;
                    w->right->b = 1;
                    leftTurn (x->parent);
                    x = root;
                }
            } else {
                RBNode *w = x->parent->left;
                if (w->b == 0) {
                    w->b = 1;
                    x->parent->b = 0;
                    rightTurn (x->parent);
                    w = x->parent->left;
                }
                if (w->right->b == 1 && w->left->b == 1) {
                    w->b = 0;
                    x = x->parent;
                } else {
                    if (w->left->b == 1) {
                        w->right->b = 1;
                        w->b = 0;
                        leftTurn (w);
                        w = x->parent->left;
                    }
                    w->b = x->parent->b;
                    x->parent->b = 1;
                    w->left->b = 1;
                    rightTurn (x->parent);
                    x = root;
                }
            }
        }
        x->b = 1;
    }

    void dropNode(RBNode *z) {
        RBNode *x, *y;
        if (!z || z == NIL) return;
        if (z->left == NIL || z->right == NIL) {
            y = z;
        } else {
            y = z->right;
            while (y->left != NIL) y = y->left;
        }
        if (y->left != NIL)
            x = y->left;
        else
            x = y->right;
        x->parent = y->parent;
        if (y->parent)
            if (y == y->parent->left)
                y->parent->left = x;
            else
                y->parent->right = x;
        else
            root = x;

        if (y != z) z->key = y->key;


        if (y->b == 1)
            afterDrop (x);

        free (y);
    }

    RBNode *findNode(int data) {

        RBNode *current = root;
        while(current != NIL)
            if(data == current->key)
                return (current);
            else
                current = data<current->key ?
                    current->left : current->right;
        return nullptr;
    }

    void drop(int k){
        RBNode * tmp = findNode(k);
        if (tmp != nullptr){
            dropNode(tmp);
        }
    }
    void clear (RBNode * p){
        if (p == nullptr) return;
        if (p == p->left && p == p->right) return;
        clear(p->right);
        clear(p->left);
        delete p;
    }
    void clear(){
        clear(root);
        root = NIL;
    }

    RBNode * getRoot(){
        return root;
    }
    void print(){}
};

#endif
