#include "mainwindow.h"
#include <QApplication>

#include <QFile>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(NasalApplication2);

    QApplication app(argc, argv);
    app.setOrganizationName("TheNasalGuys");
    app.setApplicationName("Nasal Repair Assistant");

    MainWindow mainWin;

    //QFile file(":/styles/style1.css");
    //file.open(QIODevice::ReadOnly);
    //QString style1(file.readAll());
    //app.setStyleSheet(style1);
    //file.close();

    mainWin.show();

    return app.exec();
}
