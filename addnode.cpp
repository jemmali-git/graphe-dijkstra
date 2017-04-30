#include "addnode.h"

addNode::addNode(int num)
{
    nb = num;
    couleur=QColor(255,255,255);
}
//int addNode::nodeNb = 0;
QRectF addNode::boundingRect() const
{
    return QRectF( -20, -20, 40, 40);
}

void addNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QString qstr =(QString::number(nb));
    setFlag(ItemIsMovable);  // make node movable
    //create ellipse (conf)
    QRectF rect = boundingRect();
    QBrush brusher(couleur);//colorer le noeud a l'interieur
    QPen pen;//dessiner le border
    pen.setWidth(1);
    painter->setBrush(brusher);
    painter->setPen(pen);
    painter->drawEllipse(-20,-20,40,40);
    painter->drawText(rect,Qt::AlignCenter,qstr); // draw node num

}
