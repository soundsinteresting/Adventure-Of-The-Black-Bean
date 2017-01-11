#ifndef TEXTITEM_H
#define TEXTITEM_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QMouseEvent>

class TextItem: public QGraphicsTextItem{
    Q_OBJECT
public:
    TextItem(QString name, QGraphicsItem *parent=NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    //void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    clicked();


};
#endif // TEXTITEM_H
