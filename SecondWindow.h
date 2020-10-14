//
// Created by giulia on 13/10/20.
//

#ifndef PROGRAMMAZIONE_SECONDWINDOW_H
#define PROGRAMMAZIONE_SECONDWINDOW_H

#include <QMainWindow>
#include "Observer.h"
#include "LoadResources.h"
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>


class SecondWindow : public QMainWindow, public Observer {
Q_OBJECT
public:
    explicit SecondWindow(LoadResources *res, std::vector<string> file,   QWidget *parent=0);
    virtual ~SecondWindow();
    virtual void update() override;
    LoadResources *getResources() const;


private:

    LoadResources * resources;
    QPushButton* button;

    QTextEdit * line;
    QTextEdit * text;

    std::vector<string> file;
    int perc;
};


#endif //PROGRAMMAZIONE_SECONDWINDOW_H
