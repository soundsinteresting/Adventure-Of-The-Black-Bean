#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
  //constructor
    Player(QGraphicsItem *parent=0);
  //public member function
    //walk and jump
    void moveright();
    void moveleft();
    void setwalkstate(int w){walkstate=w;}
    void moveautomatically();

    void jump();

    void keyPressEvent(QKeyEvent *event);

  //public attributes
    QImage walkpix[12];
public slots:
    void walkauto();
    void walkright();
    void walkleft();
    void jumpup();
private:
    int direction;
    int walkstate;
    float yspeed;
    int isjumping;
    QTimer *jumptimer;

};
#endif // PLAYER_H
