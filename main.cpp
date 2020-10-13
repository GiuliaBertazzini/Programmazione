#include <QVBoxLayout>
#include <QApplication>
#include "MainWindow.h"


vector <string>  addResources(){
    vector <string> filenames;

    filenames.emplace_back("../resources/File.txt");
    filenames.emplace_back("../resources/File2.txt");
    filenames.emplace_back("../resources/cat.jpg");
    filenames.emplace_back("../resources/dog.jpg");
   

    return filenames;
}

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    LoadResources loader;

    std::vector<string> f = addResources();

    MainWindow mainWindow(&loader, f);
    loader.registerObserver(&mainWindow);
    mainWindow.show();

    return app.exec();
}
