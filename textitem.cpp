#include "textitem.h"

TextItem::TextItem(QString name, QGraphicsItem *parent)
{
    setPlainText(name);
    setParentItem(parent);

}

void TextItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}


