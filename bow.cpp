#include "bow.h"
#include<QRectF>
#include <qmath.h>

static const double Pi = 3.14;
static double TwoPi = 2.0 * Pi;
Bow::Bow(addNode *sourceNode, addNode *destNode)
{
    couleur=QColor(0,0,0);
    size=1;                          //size=5;
    style=Qt::SolidLine;            //Qt::PenStyle a=Qt::DashDotLine;
    arrowSize=15;
    source = sourceNode;
    dest=destNode;
    source->lis_bow << this;
    dest->lis_bow << this;

    suivant_precedent*suiv=new suivant_precedent();
    suiv->edge1=this;
    suiv->node1=destNode;
    source->children_list1<<suiv;
    value=new QLabel();
    value->setStyleSheet("background:black;color: rgb(255,255,255); font-size: 20px;");
    value->setAlignment(Qt::AlignCenter);
    adjust();
    update();
    ///


}
QRectF Bow::boundingRect() const
{
     return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),destPoint.y() - sourcePoint.y()));
}
void Bow::adjust()
{

    if (!source || (!dest))
        return;

        QLineF line(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));
        qreal length = line.length();

        QPointF edgeOffset(line.dx() * 20 / length, line.dy() * 20 / length);
        sourcePoint = line.p1()+ edgeOffset;
        destPoint = line.p2()- edgeOffset;
        value->setGeometry((source->pos()+dest->pos()).x()/2-15,(source->pos()+dest->pos()).y()/2-15,30,30);

}
void Bow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    ///
    if (!source || (!dest))
        return;

    QLineF line(sourcePoint, destPoint);
    if (!line.length())
        return;
     QPen pen;

     pen.setStyle(style);
     pen.setWidth(size);
     pen.setBrush(couleur);
     pen.setCapStyle(Qt::RoundCap);
     pen.setJoinStyle(Qt::RoundJoin);

     painter->setPen(pen);
     painter->setBrush(couleur);

     painter->drawLine(line);
    // Draw the arrows
    double angle = ::acos(line.dx() / line.length());
    if (line.dy() >= 0)
        angle = TwoPi-angle;

    QPointF destArrowP1 = destPoint + QPointF(sin(angle - Pi / 3) * arrowSize,
                                              cos(angle - Pi / 3) * arrowSize);

    QPointF destArrowP2 = destPoint + QPointF(sin(angle - Pi + Pi / 3) * arrowSize,
                                              cos(angle - Pi + Pi / 3) * arrowSize);
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);

}

