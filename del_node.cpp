#include "del_node.h"


del_node::del_node(QWidget *parent) :
    QDialog(parent)
{
    this->setFixedSize(400,300);
    source=new QLabel(this); source->setText("Source");
    source->setGeometry(50,50,100,50);
    source1=new QSpinBox(this);
    source1->setGeometry(150,50,42,22);
///

    save=new QPushButton("SAVE",this);
    save->setGeometry(100,220,181,41);

    this->show();
}


del_node::~del_node()
{
}

