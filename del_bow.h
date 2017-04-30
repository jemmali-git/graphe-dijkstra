#ifndef DEL_BOW_H
#define DEL_BOW_H
#include <QDialog>
#include<QLabel>
#include<QSpinBox>
#include <QPushButton>


class del_bow: public QDialog
{
    Q_OBJECT

public:
     del_bow(QWidget *parent = 0);
    ~del_bow();
signals:

public slots:

public:
     QLabel*source,*destination;
     QSpinBox*source1,*destination1;
     QPushButton*save;
};

#endif // DEL_BOW_H
//

