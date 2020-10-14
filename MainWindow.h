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
    explicit MainWindow(LoadResources *res, std::vector<string> file, QWidget *parent=0);
    virtual ~MainWindow();
    virtual void update() override;
    LoadResources *getResources() const;
    QProgressBar * getProgressBar();
    QTextEdit * getText();
    QPushButton * getButton();



private slots:
    void loadResources();

private:
    LoadResources * resources;

    QPushButton * button;
    QProgressBar * progressBar;
    QProgressBar * progressByteBar;
    QTextEdit * text;

    QLabel * title;

    std::vector<string> file;



};
#endif //PROGRAMMAZIONE_MAINWINDOW_H
