//
// Created by giulia on 15/09/20.
//

#ifndef PROGRAMMAZIONE_MAINWINDOW_H
#define PROGRAMMAZIONE_MAINWINDOW_H

#include <QMainWindow>
#include "Observer.h"
#include "LoadResources.h"
#include <QProgressBar>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>

class MainWindow : public QMainWindow, public Observer {
    Q_OBJECT
public:
    explicit MainWindow(LoadResources *res, QWidget *parent = 0);
    virtual ~MainWindow();
    virtual void update() override;
    LoadResources *getResources() const;

private slots:
    void loadResources();

private:
    LoadResources * resources;

    QPushButton * button;
    QProgressBar * progressBar;
    QTextEdit * text;

    QLabel * title;



};
#endif //PROGRAMMAZIONE_MAINWINDOW_H
