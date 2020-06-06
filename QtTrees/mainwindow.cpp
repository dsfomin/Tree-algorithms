#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Vertex.h"
#include "TreeAdapter.h"
#include <math.h>

int curTree = 1;
int RightEnd = 0;
int RAD = 25;
QGraphicsScene * Scene;

AvlTreeAdapter<int> AVLT(&Singleton<AVL_Tree<int>>::getInstance());
RBTreeAdapter<int> RBT(&Singleton<RedBlackTree<int>>::getInstance());
SplayTreeAdapter<int> ST(&Singleton<SplayTree<int>>::getInstance());

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Scene = new QGraphicsScene;
    ui->treeView->setScene(Scene);
    ui->treeView->setRenderHint(QPainter::Antialiasing);
    ui->treeView->translate(400,400);
    ui->treeView->scale(1,-1);
    ui->treeView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->treeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->treeView->setAlignment(Qt::AlignCenter);
    ui->treeView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->rbtn_AVL->setChecked(true);
    Scene->setStickyFocus(true);
    this->showMaximized();
    qsrand(0);
    ui->progressBar->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


template<class T> void MainWindow::presketch(T* p){
    Scene->clear();
    delete Scene;
    Scene = new QGraphicsScene;
    ui->treeView->setScene(Scene);
    RightEnd = sketch(p, 0, -RightEnd).first;
    ui->treeView->setFocusPolicy(Qt::FocusPolicy::WheelFocus);
}


QPair <int, int> MainWindow::sketch(RBTreeNode<int> *p, int h, int y){
    if (p == nullptr) {
        QGraphicsItem * item = new Vertex(0, "black",true);
        Scene->addItem(item);
        item->setPos(v(y), v(h));
        return {y,y};
    }

    QPair <int, int> lnr = sketch(p->left, h-75, y);
    Scene->addLine(lnr.first+50, h-25, lnr.second, h-50);
    QPair<int ,int> nr = sketch(p->right, h-75, lnr.first+100);
    Scene->addLine(lnr.first+50, h-25, nr.second, h-50);
    QGraphicsItem * item = new Vertex(p->key, ((p->color == COLOR_BLACK)?"black":"red"));
    Scene->addItem(item);
    item->setPos(v(lnr.first+50), v(h));
    return {nr.first, lnr.first+50};

}

QPair<int,int> MainWindow::sketch(AVL_Node<int> * p, int h, int y){
    if (p == nullptr) return {y,y};
    QPair <int, int> lnr = sketch(p->left, h-75, y);
    if (p->left){
        Scene->addLine(lnr.first+50, h-25, lnr.second, h-50);
    }
    QPair<int ,int> nr = sketch(p->right, h-75, lnr.first+50);
    if (p->right){
        Scene->addLine(lnr.first+50, h-25, nr.second, h-50);
    }
    QGraphicsItem * item = new Vertex(p->key, "avl");
    Scene->addItem(item);
    item->setPos(v(lnr.first+50), v(h));
    return {nr.first, lnr.first+50};
}

QPair<int, int> MainWindow::sketch(TreeNode<int> * p, int h, int y){
    if (p == nullptr) return {y,y};
    QPair <int, int> lnr = sketch(p->left, h-75, y);
    if (p->left){
        Scene->addLine(lnr.first+50, h-25, lnr.second, h-50);
    }
    QPair<int ,int> nr = sketch(p->right, h-75, lnr.first+50);
    if (p->right){
        Scene->addLine(lnr.first+50, h-25, nr.second, h-50);
    }
    QGraphicsItem * item = new Vertex(p->key, "splay");
    Scene->addItem(item);
    item->setPos(lnr.first+50-25, h-25);
    return {nr.first, lnr.first+50};
}

int MainWindow::v(int x){
    return x-RAD;
}


template<class T, class D> void MainWindow::fromOneToAnother(T * p, D &tree){
    if (p == nullptr) return;
    if (p == p->left && p == p->right) return;
    fromOneToAnother(p->left, tree);
    fromOneToAnother(p->right, tree);
    tree.insert(p->key);
}




void MainWindow::on_btn_add_clicked(){
    QString str = ui->line_input->text();
    if (curTree == 1){
        if (str[0] == ' ' || str == ""){
            AVLT.insert(qrand()%10000);
            presketch(AVLT.getRoot());
            return;
        }
        QStringList lis = str.split(" ");
        for (int i = 0; i < lis.size(); ++i){
            AVLT.insert(lis[i].toInt());
        }
        ui->line_input->clear();
        presketch(AVLT.getRoot());
    } else if (curTree == 2){
        if (str[0] == ' ' || str == ""){
            RBT.insert(qrand()%10000);
            presketch(RBT.getRoot());
            return;
        }
        QStringList lis = str.split(" ");
        for (int i = 0; i < lis.size(); ++i){
            RBT.insert(lis[i].toInt());
        }
        ui->line_input->clear();
        presketch(RBT.getRoot());
    } else {
        if (str[0] == ' ' || str == ""){
            ST.insert(qrand()%10000);
            presketch(ST.getRoot());
            return;
        }
        QStringList lis = str.split(" ");
        for (int i = 0; i < lis.size(); ++i){
            ST.insert(lis[i].toInt());
        }
        ui->line_input->clear();
        presketch(ST.getRoot());
    }

}

void MainWindow::on_btn_del_clicked(){
    QString str = ui->line_input->text();
    if (str[0] == ' ' || str == ""){
        return;
    } else {
        if (curTree == 1){
            QStringList lis = str.split(" ");
            for (int i = 0; i < lis.size(); ++i){
                AVLT.erase(lis[i].toInt());
            }
            ui->line_input->clear();
            presketch(AVLT.getRoot());
        } else if (curTree == 2){
            QStringList lis = str.split(" ");
            for (int i = 0; i < lis.size(); ++i){
                RBT.erase(lis[i].toInt());
            }
            ui->line_input->clear();
            presketch(RBT.getRoot());
        } else {
            QStringList lis = str.split(" ");
            for (int i = 0; i < lis.size(); ++i){
                ST.erase(lis[i].toInt());
            }
            ui->line_input->clear();
            presketch(ST.getRoot());
        }
    }
}

void MainWindow::on_btn_z_plus_clicked()
{
    ui->treeView->scale(1.1,1.1);
}

void MainWindow::on_btn_z_minus_clicked()
{
    ui->treeView->scale(1/1.1,1/1.1);
}


void MainWindow::on_rbtn_AVL_clicked()
{
    if (curTree == 1){
        return;
    } else {
        if (curTree == 2){
            fromOneToAnother(RBT.getRoot(), AVLT);
            presketch(AVLT.getRoot());
            curTree = 1;
            RBT.clear();
        } else {
            fromOneToAnother(ST.getRoot(), AVLT);
            presketch(AVLT.getRoot());
            curTree = 1;
            ST.clear();
        }
    }
}

void MainWindow::on_rbtn_RB_clicked()
{
    if (curTree == 2){
        return;
    } else {
        if (curTree == 1){
            fromOneToAnother(AVLT.getRoot(), RBT);
            presketch(RBT.getRoot());
            curTree = 2;
            AVLT.clear();
        } else {
            fromOneToAnother(ST.getRoot(), RBT);
            presketch(RBT.getRoot());
            curTree = 2;
            ST.clear();
        }
    }
}

void MainWindow::on_rbtn_S_clicked()
{
    if (curTree == 3){
        return;
    } else {
        if (curTree == 2){
            fromOneToAnother(RBT.getRoot(), ST);
            presketch(ST.getRoot());
            curTree = 3;
            RBT.clear();
        } else {
            fromOneToAnother(AVLT.getRoot(), ST);
            presketch(ST.getRoot());
            curTree = 3;
            AVLT.clear();
        }
    }
}

void MainWindow::on_btnClear_clicked()
{
    if (curTree == 1){
        AVLT.clear();
    } else if (curTree == 2) {
        RBT.clear();
    } else {
        ST.clear();
    }
    Scene->clear();
    delete Scene;
    Scene = new QGraphicsScene;
    ui->treeView->setScene(Scene);
}

void MainWindow::on_btnTest_clicked()
{
    ui->progressBar->show();
    if (curTree == 1){
        for (int i = 0; i < 100; ++i){
            AVLT.insert(qrand()*qrand());
            presketch(AVLT.getRoot());
            for (int j = 0; j < 5000000; ++j){

            }
            ui->progressBar->setValue(i);
            QCoreApplication::processEvents();
        }
    } else if (curTree == 2){
        for (int i = 0; i < 100; ++i){
            RBT.insert(qrand()*qrand());
            presketch(RBT.getRoot());
            for (int j = 0; j < 5000000; ++j){

            }
            ui->progressBar->setValue(i);
            QCoreApplication::processEvents();
        }
    } else {
        for (int i = 0; i < 100; ++i){
            ST.insert(qrand()*qrand());
            presketch(ST.getRoot());
            for (int j = 0; j < 5000000; ++j){

            }
            ui->progressBar->setValue(i);
            QCoreApplication::processEvents();
        }
    }
    ui->progressBar->hide();
}
