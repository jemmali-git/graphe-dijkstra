#ifndef DEL_NODE_H
#define DEL_NODE_H
#include <QDialog>
#include<QLabel>
#include<QSpinBox>
#include <QPushButton>


class del_node: public QDialog
{
    Q_OBJECT

public:
     del_node(QWidget *parent = 0);
    ~del_node();
signals:

public slots:

public:
    QLabel*source;
    QSpinBox*source1;
    QPushButton*save;

};

#endif // DEL_NODE_H
//

