//
// Created by giulia on 15/09/20.
//

#ifndef PROGRAMMAZIONE_LOADRESOURCES_H
#define PROGRAMMAZIONE_LOADRESOURCES_H

#include "Subject.h"
#include "Observer.h"
#include <list>
#include <QTextEdit>
#include "File.h"
#include <QApplication>
#include <QProgressBar>
#include <QTimer>
#include <QPushButton>

using namespace std;

class LoadResources : public Subject {
public:
    LoadResources();

    virtual void registerObserver(Observer * obs) override;
    virtual void removeObserver(Observer *obs) override;
    virtual void notifyObservers() const override;

    bool loadedFile() const;
    int getFileSize() const;
    int getNumberResources() const;
    const QString & getFileName();
    void load(std::vector<string> &filenames);
    void handleFile(string t);
    void setLoad(bool l);

private:
    list<Observer*> observers;  //puntatori a classe base perchè non so quali saranno quelli concreti
    int numberResources;

    bool loaded;
    int filesize;

    QString filename;
};
#endif //PROGRAMMAZIONE_LOADRESOURCES_H
