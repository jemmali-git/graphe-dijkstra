#ifndef ADDNEWNODE_H
#define ADDNEWNODE_H

#include <QPainter>
#include <QGraphicsItem>
class addNewNode : public QGraphicsItem
{
public:
    addNewNode();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool pressed;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *);
};

#endif // ADDNEWNODE_H
