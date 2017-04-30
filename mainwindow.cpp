#include "mainwindow.h"
#include <iostream>
#include "bow.h"
#include "addnode.h"
#include "suivant_precedent.h"
#include<QLabel>
#include<QGraphicsProxyWidget>

static const qreal MAX = 1000;
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    graphicsView=new QGraphicsView(this);
    setFixedSize(700,600);

    graphicsView->setGeometry(75,25,550,550);
    graphicsView->setFixedSize(550,550);

    graphicsView->setStyleSheet("background:rgb(150,150,150,0);");

    scene = new QGraphicsScene(graphicsView);

    QRectF rect(-200, -200, 525, 525);
    scene->setSceneRect(rect);

    QPen pen;
    QColor color;
    color.setRgb(0,0,0,150);
    pen.setBrush(color);

    scene->addRect(rect,pen,color);
    scene->setSceneRect(rect);
    graphicsView->setScene(scene);


    graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    graphicsView->setRenderHint(QPainter::Antialiasing);
    graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    graphicsView->setMinimumSize(550, 550);
    graphicsView->setScene(scene);


    nodeNb = 0;

    new_node=new QPushButton("NEW_NODE",this);
    new_Bow=new QPushButton("NEW_BOW",this);
    remove_node=new QPushButton("DEl_NODE",this);
    remove_Bow=new QPushButton("DEl_BOW",this);

    dijkstra_butt=new QPushButton("DIJKSTRA",this);
    clear_butt=new QPushButton("CLEAR",this);

    new_node->setGeometry(630,25,70,40);
    connect(new_node,SIGNAL(clicked()),this,SLOT(add_New_Node()));

    new_Bow->setGeometry(630,65,70,40);
    connect(new_Bow,SIGNAL(clicked()),this,SLOT(New_Bow_clicked()));

    remove_node->setGeometry(630,145,70,40);
    connect(remove_node,SIGNAL(clicked()),this,SLOT(delete_node()));

    remove_Bow->setGeometry(630,105,70,40);
    connect(remove_Bow,SIGNAL(clicked()),this,SLOT(delete_bow()));

    dijkstra_butt->setGeometry(0,25,70,40);
    connect(dijkstra_butt,SIGNAL(clicked()),this,SLOT(dijkstra()));

    clear_butt->setGeometry(0,105,70,40);
    connect(clear_butt,SIGNAL(clicked()),this,SLOT(clear()));
    ////
    node_select=new QLineEdit(this);
    node_select->setText("INPUT");
    node_select->setStyleSheet("background:gray;color: black; font-size: 15px;");
    node_select->setAlignment(Qt::AlignCenter);
    node_select->setFixedHeight(40);
    node_select->setFixedWidth(70);

    node_select->setGeometry(0,65,node_select->width(),node_select->height());
    ///
    timerId = startTimer(0);
    ////


}

MainWindow::~MainWindow()
{
    killTimer(timerId);
}
///
void MainWindow::delete_bow1()
{
    addNode*node_begin=new addNode();
    addNode*node_end=new addNode();

    foreach(addNode*var1,node_list)
    {
        if(var1->nb==dialog_delte_bow->source1->value())
            node_begin=var1;
        else if(var1->nb==dialog_delte_bow->destination1->value())
             node_end=var1;
    }
    foreach(Bow*var1,bow_list)
    {
         if((var1->source==node_begin)&&(var1->dest==node_end))
         {
            var1->hide();
            scene->removeItem(var1);
            bow_list.removeOne(var1);
            scene->update();

            QGraphicsProxyWidget *proxy;
            proxy = proxy->createProxyForChildWidget(var1->value );
            proxy->hide();
            scene->removeItem( proxy );
            scene->update();
         }
    }
}
void MainWindow::delete_bow()
{
    dialog_delte_bow= new del_bow(this);
    dialog_delte_bow->show();
    connect(dialog_delte_bow->save,SIGNAL(clicked()),dialog_delte_bow,SLOT(accept()));
    connect(dialog_delte_bow->save,SIGNAL(clicked()),this,SLOT(delete_bow1()));
}
void MainWindow::delete_node1()
{
    foreach(addNode*var1,node_list)
    {
        if(var1->nb==(dialog_delte_node->source1->value()))
        {
            scene->removeItem(var1);
            node_list.removeOne(var1);
            scene->update();
            break;
        }
    }
}
void MainWindow::delete_node()
{
    dialog_delte_node= new del_node(this);
    dialog_delte_node->source1->setValue(0);
    dialog_delte_node->show();
    connect(dialog_delte_node->save,SIGNAL(clicked()),dialog_delte_node,SLOT(accept()));
    connect(dialog_delte_node->save,SIGNAL(clicked()),this,SLOT(delete_node1()));
}
void MainWindow::clear()
{
    foreach (addNode*var1, node_list)
    {
        foreach (Bow*var2, var1->lis_bow)
        {
            var2->couleur=QColor(0,0,0);
            var2->size=1;
            var2->style=Qt::SolidLine;
        }
        scene->update();
    }
}
void MainWindow::dijkstra()
{

    int depart=node_select->text().toInt();

    addNode*depart_node=number_To_Node(depart);
    if(!depart)
        return;
     QList<addNode*> node_list_aux;

    QList<Bow*> edge_list_aux;

    node_list_aux=node_list;

    QList<int> node_list_distance;

    for(int i=0;i<nodeNb+1;i++)
    {
        node_list_distance<<MAX;
        edge_list_aux<<0;
    }


    foreach (addNode*var1, node_list_aux)
    {
         node_list_distance[var1->nb]=distance(depart_node,var1);
         foreach (suivant_precedent*var2, depart_node->children_list1)
         {
             if(var2->node1==var1)
                 edge_list_aux[var1->nb]=var2->edge1;
         }
    }

    node_list_aux.removeOne(depart_node);

    depart_node=min_distance(depart_node,node_list_aux,node_list_distance,edge_list_aux);

    addNode*depart_node_aux;

    while(!node_list_aux.isEmpty())
    {
        update1(depart_node,node_list_aux,node_list_distance,edge_list_aux);
        depart_node_aux=depart_node;
        depart_node=min_distance(depart_node,node_list_aux,node_list_distance,edge_list_aux);
        if(depart_node_aux==depart_node)
            break;
    }

}
void MainWindow::update1(addNode*depart_node, QList<addNode *> &node_list_aux,
                          QList<int> &node_list_distance,QList<Bow*>&edge_list_aux)
{
    foreach (addNode*var1, node_list_aux) {
        node_list_distance[var1->nb]=
        qMin(qreal(node_list_distance[var1->nb]),qreal(node_list_distance[depart_node->nb])+distance(depart_node,var1));
        if(node_list_distance[var1->nb]==(qreal(node_list_distance[depart_node->nb])+distance(depart_node,var1)))
        {
            foreach (suivant_precedent*var2, depart_node->children_list1)
            {
                if(var2->node1==var1)
                    edge_list_aux[var1->nb]=var2->edge1;
            }
        }
    }
}
addNode*MainWindow::min_distance(addNode*depart,QList<addNode*> &node_list_aux,
                               QList<int>&node_list_distance,QList<Bow*>&edge_list_aux)
{
    int min=MAX;
    addNode*min_node=depart;
    foreach (addNode*var1, node_list_aux) {
        if(node_list_distance[var1->nb]<min)
        {
                min=node_list_distance[var1->nb];
                min_node=var1;
        }

    }
    if(edge_list_aux[min_node->nb]!=0)
    {
        edge_list_aux[min_node->nb]->couleur=QColor(0,255,0);
        edge_list_aux[min_node->nb]->size=5;
        edge_list_aux[min_node->nb]->style=Qt::DashDotLine;
    }

    scene->update();
    node_list_aux.removeOne(min_node);
    return min_node;

}
addNode*MainWindow::number_To_Node(int num)
{
    foreach (addNode*var1, node_list) {
       if(var1->nb==num)
           return var1;
    }
}

int MainWindow::distance(addNode*node1,addNode*node2)
{
    int dist=-1;
    if(node1==node2)
    {
        return 0;
    }
    foreach (suivant_precedent*var1, node1->children_list1)
    {
        if(var1->node1==node2)
        {
            if(var1->edge1->value)
                dist=var1->edge1->value->text().toInt();
        }
    }
    if(dist==-1)
        return MAX;
    else
    return dist;

}

void MainWindow::add_New_Node()
{
    nodeNb++;
    addNode *aux = new addNode(nodeNb);
    scene->addItem(aux);
    node_list.push_back(aux);
}
void MainWindow::draw_bow()
{
   int begin1=addBow->source1->value();
   int  end1=addBow->destination1->value();
   if((!begin1)||(!end1)||(begin1>nodeNb)||(end1>nodeNb))
       return;

   addNode*node_begin=new addNode();
   addNode*node_end=new addNode();

    foreach(addNode*var1,node_list)
    {
        if(var1->nb==begin1)
            node_begin=var1;
        else if(var1->nb==end1)
            node_end=var1;
    }
    Bow*bow1=new Bow(node_begin,node_end);
    bow1->value->setText(QString::number(addBow->valeur1->value()));
    scene->addWidget(bow1->value);
    scene->addItem(bow1);
    bow_list<<bow1;
}
void MainWindow::New_Bow_clicked()
{
    addBow = new newBow();
    addBow->setModal(true);
    addBow->show();
    connect(addBow->save,SIGNAL(clicked()),this,SLOT(draw_bow()));
    connect(addBow->save,SIGNAL(clicked()),addBow,SLOT(accept()));

}
void MainWindow::timerEvent(QTimerEvent*event)
{
    foreach (addNode*var1, node_list)
    {
        foreach (Bow*var2, var1->lis_bow) {
           var2->adjust();
        }
    }
}
