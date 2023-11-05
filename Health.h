#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QObject>

class Health : public QGraphicsTextItem {
    Q_OBJECT

public:
    Health(QGraphicsItem *parent = nullptr);
    void decrease();
    int getHealth();

private:
    int health;
};



#endif
