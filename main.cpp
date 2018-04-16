
#include <QApplication>
#include <QGraphicsScene>
#include "myrect.h"
#include <QGraphicsView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //create a scene
    QGraphicsScene *scene = new QGraphicsScene();

    //create an item to put into scene
    MyRect *player = new MyRect();
    player->setRect(0,0,100,100);

    //add the item to the scene
    scene->addItem(player);

    // make rect
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add view
    QGraphicsView *view = new QGraphicsView();
    view->setScene(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2,view->height()-player->rect().height());
    view->setFixedSize(800,600);
    view->show();

    return a.exec();
}

