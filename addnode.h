#ifndef ADDNODE_H
#define ADDNODE_H

#include <QPainter>
#include <QGraphicsItem>
#include <string>
#include<QList>
#include"suivant_precedent.h"

class Bow;
class addNode : public QGraphicsItem
{
public:

    addNode(int num=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
public:
    int nb;
    QList< Bow* > lis_bow;
    QList<suivant_precedent*> children_list1;
    QColor couleur;

};

#endif // ADDNODE_H
