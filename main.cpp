#include <QApplication>
#include <QMessageBox>
#include "Game.h"

Game *game;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);


    int response = QMessageBox::question(nullptr, "Palestine", "Do you want to start the game?", QMessageBox::Yes | QMessageBox::No);

    if (response == QMessageBox::Yes) {

        game = new Game();
        game->show();
        return a.exec();
    } else {

        return 0;
    }
}
