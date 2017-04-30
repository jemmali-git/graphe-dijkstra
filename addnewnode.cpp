#include "addnewnode.h"

addNewNode::addNewNode()
{
    pressed = false;
}

QRectF addNewNode::boundingRect() const
{

    return QRectF(-1,-1,90,90);
}

void addNewNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    setFlag(ItemIsMovable);
    QBrush brusher(Qt::white);
    QPen pen;
    pen.setWidth(5);
    painter->setPen(pen);
    painter->drawEllipse(rect);
    painter->drawText(rect,"1");
}

void addNewNode::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    pressed = true;
    update();
    QGraphicsItem::mousePressEvent(e);
}

void addNewNode::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(e);
}
