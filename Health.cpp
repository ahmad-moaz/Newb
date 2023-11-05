#include "Health.h"
#include <QFont>
#include <QDialog>
#include <QLabel>
#include<QVBoxLayout>
#include <QMessageBox>
#include "Game.h"
extern Game * game;

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent){
    health = 3;
    setPlainText(QString("Health : ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}
enum GameState { Running, Paused, Stopped };
GameState gameState = Running;

void Health::decrease() {
   health--;
    if(health==0) {
       gameState = Stopped;
       int sc = game->score->getScore();
       QString message = "Good Job! You tried your best\n";
       message += "Your Score: " + QString::number(sc);
       QMessageBox::information(nullptr, "Game Over", message);
       exit(0);}
   setPlainText(QString("Health : ") + QString::number(health));
}

int Health::getHealth() {
    return health;
}

