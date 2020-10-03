#include <iostream>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    LoadResources loader;

    MainWindow mainWindow(&loader);
    loader.registerObserver(&mainWindow);
    mainWindow.show();

    return app.exec();
}
