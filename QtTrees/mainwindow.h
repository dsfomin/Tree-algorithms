#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <bits/stdc++.h>
#include <QStack>
#include "../includes/RedBlackTree.h"
#include "../includes/SplayTree.h"
#include "../includes/AVL_Tree.h"

// TODO: check if it works as expected
template <typename TreeType>
class Singleton {
private:
    Singleton() {}

public:
    Singleton(Singleton const&) = delete;
    void operator=(Singleton const&) = delete;

    static TreeType& getInstance() {
        static TreeType instance;
        return instance;
    }
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   template<class T> void presketch(T* p);
   int v(int x);
   QPair<int, int> sketch(TreeNode<int> * p, int h, int y);
   QPair<int, int> sketch(AVL_Node<int> * p, int h, int y);
   QPair<int, int> sketch(RBTreeNode<int> * p, int h, int y);

   template<class T, class D> void fromOneToAnother(T * p, D &tree);
private slots:
    void on_btn_add_clicked();

    void on_btn_del_clicked();

    void on_btn_z_plus_clicked();

    void on_btn_z_minus_clicked();

    void on_rbtn_AVL_clicked();

    void on_rbtn_RB_clicked();

    void on_rbtn_S_clicked();

    void on_btnClear_clicked();

    void on_btnTest_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
