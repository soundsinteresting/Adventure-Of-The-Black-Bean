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
        bean= new Player();
        scene->addItem(bean);

        bean->moveautomatically();

     //create the buttons
        QGraphicsPixmapItem *board=new QGraphicsPixmapItem();
        board->setPixmap(QPixmap(":/pictures/resoureces/pictures/4buttonboard.png"));
        board->setPos(800-150,600-138-50);


        TextItem *text1= new TextItem(QString("START"),board);
        text1->setPos(150/2-text1->boundingRect().width()/2,20);
        connect(text1,SIGNAL(clicked()),this,SLOT(conversation1()));


        TextItem *text2= new TextItem(QString("LOAD GAMES"),board);
        text2->setPos(150/2-text2->boundingRect().width()/2,50);


        TextItem *text3= new TextItem(QString("OPERATING INSTRUCTIONS"),board);
        text3->setPos(150/2-text3->boundingRect().width()/2,80);


        TextItem *text4= new TextItem(QString("QUIT"),board);
        text4->setPos(150/2-text4->boundingRect().width()/2,110);
        connect(text4,SIGNAL(clicked()),this,SLOT(close()));




        scene->addItem(board);


}

void Game::conversation1()
{
    //qDebug("function conversation1 is deployed");
    scene->clear();
    QGraphicsPixmapItem *block[32];
    for(int i=0;i<32;i++){
        block[i]= new QGraphicsPixmapItem();
        block[i]->setPixmap(QPixmap(":/pictures/resoureces/pictures/block brick 2nd floor middle.png"));
        block[i]->setPos(25*i,570);
        scene->addItem(block[i]);
    }
    bean= new Player();
    scene->addItem(bean);
    bean->setPixmap(QPixmap::fromImage(bean->walkpix[0]));
    bean->setPos(100,570-120);
    bean->setFlag(QGraphicsItem::ItemIsFocusable);
    bean->setFocus();






}
