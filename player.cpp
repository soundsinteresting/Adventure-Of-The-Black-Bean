#include "player.h"
#include <QTimer>
#include <stdlib.h>
#include <QKeyEvent>
#include <QTime>
#include <QCoreApplication>


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
    isjumping=0;
}

void Player::moveright()
{
    QTimer *timer1= new QTimer();
    QTimer *timer3= new QTimer();
    QTimer *timer2= new QTimer();
    timer1->setSingleShot(true);
    walkstate=1;
    connect(timer1,SIGNAL(timeout()),this,SLOT(walkright()));
    timer1->start(20);



    timer2->setSingleShot(true);
    connect(timer2,SIGNAL(timeout()),this,SLOT(walkright()));
    timer2->start(40);



    timer3->setSingleShot(true);
    connect(timer3,SIGNAL(timeout()),this,SLOT(walkright()));
    timer3->start(60);




}

void Player::moveleft()
{

    QTimer *timer1= new QTimer();
    QTimer *timer3= new QTimer();
    QTimer *timer2= new QTimer();
    timer1->setSingleShot(true);
    walkstate=7;
    connect(timer1,SIGNAL(timeout()),this,SLOT(walkleft()));
    timer1->start(20);

    timer2->setSingleShot(true);
    connect(timer2,SIGNAL(timeout()),this,SLOT(walkleft()));
    timer2->start(40);

    timer3->setSingleShot(true);
    connect(timer3,SIGNAL(timeout()),this,SLOT(walkleft()));
    timer3->start(60);


}

void Player::moveautomatically()
{

    setPixmap(QPixmap::fromImage(walkpix[0]));
    setPos(50,550-120);
    direction=1;
    QTimer *timer= new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(walkauto()));
    timer->start(70);
}

void Player::jump()
{
    isjumping=1;
    yspeed=20;
    //delete jumptimer;
    jumptimer= new QTimer();
    connect(jumptimer,SIGNAL(timeout()),this,SLOT(jumpup()));
    jumptimer->start(10);
}

void Player::keyPressEvent(QKeyEvent *event)
{

       if (event->key()==Qt::Key_Left){
           if(pos().x()>0)
           moveleft();
       }
       if (event->key()==Qt::Key_Right){
           if (pos().x()<800-100)
           moveright();
       }
       if (event->key()==Qt::Key_Space){
           if(isjumping==0){
               jump();}
       }
       /*if (event->key()==Qt::Key_Down){
           if(pos().y()<600-100)
           setPos(x(),y()+10);
       }
       if (event->key()==Qt::Key_Space){
           bullet *bull=new bullet();
           bull->setPos(x()+25,y());
           scene()->addItem(bull);
           if (bulletsound->state()==QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);

           }
           if (bulletsound->state()==QMediaPlayer::StoppedState){
                bulletsound->play();
           }


       }*/

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

void Player::walkright()
{
    setPixmap(QPixmap::fromImage(walkpix[walkstate]));
    setPos(x()+5+isjumping*10,y());
    walkstate++;
    walkstate%=3;
}

void Player::walkleft()
{

    setPixmap(QPixmap::fromImage(walkpix[walkstate]));
    setPos(x()-5-isjumping*10,y());
    walkstate++;
    walkstate%=3;
    walkstate+=6;
}

void Player::jumpup()
{
    //qDebug("jumpup function is deployed");

    if(y()<=570-120){
        setPos(x(),y()-yspeed*0.8);
        yspeed-=0.8;
    }
    else{
        setPos(x(),570-120);
        disconnect(jumptimer,SIGNAL(timeout()),this,SLOT(jumpup()));
        delete jumptimer;
        yspeed=0;
        isjumping=0;
    }
}
