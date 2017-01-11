#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "player.h"

class Game:public QGraphicsView{
   //Q_OBJECT
public:
  //public member functions
    Game(QWidget *parent=NULL);
    void displaymainmeneu();
private:
  //public attributes
    QGraphicsScene *scene;


};
#endif // GAME_H
