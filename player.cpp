#include "player.h"
#include <QTimer>
#include <stdlib.h>


Player::Player(QGraphicsItem *parent)
{
    walkpix[0]=QImage(":/pictures/resoureces/pictures/bb walk mouthshut state1.png");
    walkpix[1]=QImage(":/pictures/resoureces/pictures/bb walk mouthshut state2.png");
    walkpix[2]=QImage(":/pictures/resoureces/pictures/bb walk mouthshut state3.png");
    walkpix[3]=QImage(":/pictures/resoureces/pictures/bb walk mouthopen state1.png");
    walkpix[4]=QImage(":/pictures/resoureces/pictures/bb walk mouthopen state2.png");
    walkpix[5]=QImage(":/pictures/resoureces/pictures/bb walk mouthopen state3.png");
    for(int i=6;i<12; i++){
        //walkpix[i]= walkpix[i-6].scaled(walkpix[i-6].width()*-1,walkpix[i-6].height());
        walkpix[i]=walkpix[i-6].mirrored(true,false);


    }

    //initialize
    walkstate=0;
}

void Player::moveright()
{
    walkstate++;
    walkstate%=3;
    /*if(walkstate==0){
        walkstate+=(rand()%2)*3;
    }*/
    setPixmap(QPixmap::fromImage(walkpix[walkstate]));
    setPos(x()+5,y());
}

void Player::moveleft()
{
    walkstate++;
    walkstate%=3;
    /*if(walkstate==0){
        walkstate+=(rand()%2)*3;
    }*/
    walkstate+=6;
    setPixmap(QPixmap::fromImage(walkpix[walkstate]));
    setPos(x()-5,y());

}

void Player::moveautomatically()
{

    setPixmap(QPixmap::fromImage(walkpix[0]));
    setPos(50,550-120);
    direction=1;
    QTimer *timer= new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(walkauto()));
    timer->start(50);
}

void Player::walkauto()
{
    if(direction==1 && x()<=800-138-60){
        moveright();
    }
    if(direction==1 && x()>800-138-60){
        direction=-1;
        walkstate=6;
        setPixmap(QPixmap::fromImage(walkpix[6]));
        moveleft();
    }
    if(direction==-1 && x()>=60){
        moveleft();
    }
    if(direction==-1 && x()<60 ){
        direction=1;
        setPixmap(QPixmap::fromImage(walkpix[0]));
        walkstate=0;
        moveright();
    }

}
