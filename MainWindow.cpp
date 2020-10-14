//
// Created by giulia on 20/09/20.
//
#include <iostream>
#include "MainWindow.h"
#include <QDesktopWidget>
#include <QPainter>



MainWindow::MainWindow(LoadResources *res, std::vector<string> f, QWidget *parent) : QMainWindow(parent), resources(res), file(f){

    //imposta titolo e dimensione della finestra
    this->setWindowTitle("Laboratorio di programmazione");
    this->setFixedSize(QSize(600, 400));

    //imposta il testo di informazione
    title = new QLabel("Classe che carica file di risorse e aggiorna una progress bar per il numero di risorse e una per i byte caricati (con QT)", this);
    title -> setGeometry(QRect(QPoint(100, 20), QSize(400, 100)));
    title -> setWordWrap(true);
    title -> setAlignment(Qt::AlignCenter);
    QFont font = title -> font();
    font.setPointSize(11);
    title -> setFont(font);

    //imposta il bottone
    button = new QPushButton("Carica Risorse", this);
    button -> setGeometry(QRect(QPoint(205, 200), QSize(190, 30)));

    //imposta la progress bar
    progressBar = new QProgressBar(this);
    progressBar -> setGeometry(QRect(QPoint(150, 140), QSize(300, 30)));

    progressByteBar = new QProgressBar(this);
    progressByteBar -> setGeometry(QRect(QPoint(150, 170),QSize(300, 30)));
    progressByteBar -> setFormat("%v");


    //imposta il campo di testo;
    text = new QTextEdit(this);
    text-> setGeometry(QRect(QPoint(50, 240), QSize(500, 140)));
    text -> setText("Pronto a caricare le risorse! \n");
    text -> setReadOnly(true);

    progressBar -> setMinimum(0);
    progressBar -> setMaximum(1000);
    progressBar -> setValue(0);

    progressByteBar -> setMinimum(0);
    progressByteBar -> setMaximum(100);
    progressByteBar -> setValue(0);

    resources = res;



    //connette il bottone alla funzione che deve attivare; released() signal per push button
    connect(button, SIGNAL(released()), this ,SLOT(loadResources()));
}

MainWindow::~MainWindow() {
    resources -> removeObserver(this);
}

LoadResources* MainWindow::getResources() const {
    return resources;
}

void MainWindow::update() {

    if(resources->loadedFile()) {
        //aggiorna la percentuale della progress bar
        int percentage = progressBar -> value()+ (1000/resources->getNumberResources());
        progressBar -> setValue(percentage);

        int byteLoaded = progressByteBar -> value() + resources->getFileSize();
        progressByteBar -> setValue(byteLoaded);

        //aggiorna il testo
        QString log = "Caricato correttamente il file " + QString(resources->getFileName()) + QString(", ") +QString::number(resources->getFileSize()) +QString(" bytes.");
        text->append(log);

        //aggiorna il testo del bottone
        QString percentText = QString("Risorse Caricate!");
        button->setText(percentText);

    }
    else {
        QString log = "Non è stato possibile caricare il file " + QString(resources -> getFileName());
        text->append(log);
    }
}


void MainWindow::loadResources() {
    progressBar->setValue(0);
    text -> setText("Carico le risorse...");

    resources -> load(file);

}


QProgressBar * MainWindow::getProgressBar() {
    return progressBar;
}

QTextEdit * MainWindow::getText() {
    return text;
}

QPushButton * MainWindow::getButton(){
    return button;
}


