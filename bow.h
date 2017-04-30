#ifndef BOW_H
#define BOW_H
#include<QGraphicsItem>
#include<addnode.h>
#include<QLabel>
class Bow: public QGraphicsItem
{
public:
    Bow(addNode*sourceNode, addNode*destNode);
    QRectF boundingRect() const;
    void adjust();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
public:
    addNode*dest;
    addNode*source;
    QPointF sourcePoint,destPoint;
    qreal arrowSize;
    ///

    QColor couleur;
    QLabel*value;
    ///
    int size;
    Qt::PenStyle style;
};

#endif // BOW_H
