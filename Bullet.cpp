#include "Bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Score.h"
#include "Game.h"

extern Game * game;


Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/bullet2.png"));

     QTimer * timer = new QTimer();
     connect(timer, SIGNAL(timeout()), this, SLOT(move()));

     timer->start(50);
}

void Bullet::move() {

    QList<QGraphicsItem *> colliding_item = collidingItems();
    for(int i = 0; i < colliding_item.size(); i++) {
        if(typeid(*(colliding_item[i])) == typeid(Enemy)) {
            game->score->increase();
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);
            delete colliding_item[i];
            delete this;
            return ;
        }
    }

    setPos(x(), y() - 10);
    if(pos().y() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}

