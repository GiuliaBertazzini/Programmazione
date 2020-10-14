//
// Created by giulia on 13/10/20.
//

#include <iostream>
#include "SecondWindow.h"
#include <QDesktopWidget>
#include <QPainter>
#include "MainWindow.h"

SecondWindow::SecondWindow(LoadResources *res, std::vector<string> f,  QWidget *parent) : QMainWindow(parent), resources(res), file(f), perc(0) {


    //imposta titolo e dimensione della finestra
    this->setWindowTitle("Laboratorio di programmazione, seconda finestra");
    this->setFixedSize(QSize(600, 400));


    line = new QTextEdit(this);
    line -> setGeometry(QRect(QPoint(185, 30), QSize(250, 30)));
    line -> setText("Attendo...");


    //imposta il campo di testo;
    text = new QTextEdit(this);
    text-> setGeometry(QRect(QPoint(50, 70), QSize(500, 300)));
    text -> setText("In attesa di caricare le risorse... \n");
    text -> setReadOnly(true);

}

SecondWindow::~SecondWindow() {
    resources -> removeObserver(this);
}

LoadResources* SecondWindow::getResources() const {
    return resources;
}

void SecondWindow::update() {

    if(resources->loadedFile()) {
        perc = perc + (1000/resources->getNumberResources());
        //aggiorna il testo
        QString log = QString::number(perc/10) + "% ---> ho caricato il file " + QString(resources->getFileName());
        text->append(log);


        //aggiorna il testo
        line -> setText("Le risorse sono state caricate!");

    }
    else {
        QString log = "Non è stato possibile caricare il file " + QString(resources -> getFileName());
        text->append(log);
    }
}

