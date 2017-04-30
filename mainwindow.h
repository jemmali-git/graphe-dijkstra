#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "addnewnode.h"

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "addnode.h"
#include <QList>
#include <string>
#include "newbow.h"
#include <QPushButton>
#include<QGraphicsView>
#include<QLineEdit>
#include "del_node.h"
#include "del_bow.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = 0);
    ~MainWindow();
      void timerEvent(QTimerEvent *event);
      ///
      int distance(addNode*node1,addNode*node2);
      addNode*number_To_Node(int num);
      addNode*min_distance(addNode*depart, QList<addNode *> &node_list_aux, QList<int> &node_list_distance,QList<Bow*>&edge_list_aux);
      void update1(addNode*min_node,QList<addNode*>&node_list_aux,QList<int>&node_list_distance,QList<Bow*>&edge_list_aux);

public slots:
    void draw_bow();
    void New_Bow_clicked();
    void add_New_Node();
    ///
    void delete_node();
    void delete_node1();
    ///
    void delete_bow();
    void delete_bow1();
    ///
     void dijkstra();
     void clear();

public:
    QGraphicsView*graphicsView;
    QGraphicsScene *scene;

    QList<addNode *> node_list;
    QList<Bow*> bow_list;

    int nodeNb;
    newBow*addBow;

    QPushButton*new_Bow;
    QPushButton*new_node;
    QPushButton*remove_node;
    QPushButton*remove_Bow;
    QPushButton*dijkstra_butt;
    QPushButton*clear_butt;
    int timerId;

    ///
    QLineEdit*node_select;
    ///
    del_node*dialog_delte_node;
    del_bow*dialog_delte_bow;
};
#endif // MAINWINDOW_H
