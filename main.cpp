//#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QtWidgets>


#include <QTextCodec>
#include "graphicsview.h"

int main(int argc, char *argv[])
{
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("System"));
//    QTextCodec::setCodecForLocale  (QTextCodec::codecForName("System"));
//    QTextCodec::setCodecForTr      (QTextCodec::codecForName("System"));

    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    GraphicsView w;
    //w.setGeometry(0,0,w.width(),w.height());
    w.show();


    return a.exec();
}
