#include <QVBoxLayout>
#include <QApplication>
#include "MainWindow.h"
#include "SecondWindow.h"
#include "LoadResources.h"
#include <iostream>


vector <string>  addResources(){
    vector <string> filenames;

    filenames.emplace_back("../resources/File4.txt");
    filenames.emplace_back("../resources/File2.txt");
    filenames.emplace_back("../resources/File3.txt");
    filenames.emplace_back("../resources/File.txt");
    filenames.emplace_back("../resources/dog.jpg");
    filenames.emplace_back("../resources/cat.jpg");


    return filenames;
}

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    LoadResources loader;

    std::vector<string> f = addResources();



    MainWindow mainWindow(&loader, f);
    SecondWindow secondWindow(&loader, f);
    loader.registerObserver(&mainWindow);
    loader.registerObserver(&secondWindow);

    secondWindow.show();
    mainWindow.show();

    return app.exec();
}
