#include "game.h"
#include <QGraphicsPixmapItem>
#include <QDebug>
#include "textitem.h"


Game::Game(QWidget *parent){
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
}

void Game::displaymainmeneu()
{
    //create the map blocks
    QGraphicsPixmapItem *block[8];
    for(int i=0;i<8;i++){
        block[i]= new QGraphicsPixmapItem();
        scene->addItem(block[i]);
        if(i%4==0){
            block[i]->setPixmap(QPixmap(":/pictures/resoureces/pictures/block 1st floor with stone middle.png"));
            block[i]->setPos(100*i,550);
            if(!block[i]->pixmap()){qDebug("Pixmap is not set");}

        }
        if(i%4!=0){
            block[i]->setPixmap(QPixmap(":/pictures/resoureces/pictures/block 1st floor middle.png"));
            block[i]->setPos(100*i,550);
            if(!block[i]->pixmap()){qDebug("Pixmap is not set");}
    }

    }
    //create the title text
        QGraphicsTextItem *titletext= new QGraphicsTextItem(QString("The Adventure of The Pink Bean"));
        QFont titlefont("smooth", 25);
        titletext->setFont(titlefont);

        int txPos=this->width()/2-titletext->boundingRect().width()/2;
        int tyPos= 150;
        titletext->setPos(txPos,tyPos);
        scene->addItem(titletext);

     //create the walking bean
        Player *bean= new Player();
        scene->addItem(bean);
        bean->moveautomatically();

     //create the buttons
        QGraphicsPixmapItem *board=new QGraphicsPixmapItem();
        board->setPixmap(QPixmap(":/pictures/resoureces/pictures/4buttonboard.png"));
        board->setPos(800-150,600-138-50);


        TextItem *text1= new TextItem(QString("START"),board);
        text1->setPos(150/2-text1->boundingRect().width()/2,20);


        TextItem *text2= new TextItem(QString("LOAD GAMES"),board);
        text2->setPos(150/2-text2->boundingRect().width()/2,50);


        TextItem *text3= new TextItem(QString("OPERATING INSTRUCTIONS"),board);
        text3->setPos(150/2-text3->boundingRect().width()/2,80);


        TextItem *text4= new TextItem(QString("QUIT"),board);
        text4->setPos(150/2-text4->boundingRect().width()/2,110);
        connect(text4,SIGNAL(clicked()),this,SLOT(close()));




        scene->addItem(board);


}
