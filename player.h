#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    //constructor
    Player(QGraphicsItem *parent=0);
    //public member function
    void moveright();
    void moveleft();
    void moveautomatically();
public slots:
    void walkauto();
private:
    int direction;
    QImage walkpix[12];
    int walkstate;

};
#endif // PLAYER_H
