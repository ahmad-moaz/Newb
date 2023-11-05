#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/plane.png"));
}

void Player::keyPressEvent(QKeyEvent *event){

        if((event->key() == Qt::Key_Left || event->key() == Qt::Key_A) && pos().x() > 0) {

            setPos(x() - 10, y());
        }
        else if((event->key() == Qt::Key_Right || event->key() == Qt::Key_D) && pos().x() + 100 < 800) {
            setPos(x() + 10, y());
        }
        else if((event->key() == Qt::Key_Up || event->key() == Qt::Key_W) && pos().y() > 0) {
            setPos(x(), y() - 10);

        }
        else if((event->key() == Qt::Key_Down || event->key() == Qt::Key_S) && pos().y() + 100 < 600) {
            setPos(x(), y() + 10);
        }
        else if(event->key() == Qt::Key_Space) {
            Bullet * bullet = new Bullet();
            bullet->setPos(x(), y());


            scene()->addItem(bullet);
        }
}

void Player::spawn(){

    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
