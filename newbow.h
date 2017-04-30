#ifndef NEWBOW_H
#define NEWBOW_H

#include <QDialog>
#include<QLabel>
#include<QSpinBox>
#include <QPushButton>


class newBow : public QDialog
{
    Q_OBJECT

public:
     newBow(QWidget *parent = 0);
    void setMax(int maxNode);
    int sourceVal=0,destinationVal=0,val=0;
    ~newBow();
signals:
   void saveClicked();

 public slots:

public:
    QLabel*source,*destination,*valeur;
    QSpinBox*source1,*destination1,*valeur1;
    QPushButton*save;

};

#endif // NEWBOW_H
