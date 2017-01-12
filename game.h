#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "player.h"
#include <QObject>

class Game:public QGraphicsView{
   Q_OBJECT

public:
  //public member functions
    Game(QWidget *parent=NULL);
    void displaymainmeneu();

  //public attributes:
    Player *bean;

public slots:
    void conversation1();


private:
  //public attributes
    QGraphicsScene *scene;


};
#endif // GAME_H
