#include "Enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h>
#include "Game.h"

extern Game * game;
Enemy::Enemy(QGraphicsItem* parent) :QObject(), QGraphicsPixmapItem(parent) {

    int random = rand() % 700;
    setPos(random, 0);

    setPixmap(QPixmap(":/images/enemy.jpg"));
     QTimer * timer = new QTimer();
     connect(timer, SIGNAL(timeout()), this, SLOT(move()));

     timer->start(50);
}

void Enemy::move() {

    setPos(x(), y() + 5);


    if(pos().y() + 100 > 600) {

        game->health->decrease();        
        scene()->removeItem(this);
        delete this;
    }
}
