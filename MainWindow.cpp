//
// Created by giulia on 20/09/20.
//

#include "MainWindow.h"
#include <QDesktopWidget>
#include <QPainter>

MainWindow::MainWindow(LoadResources *res, QWidget *parent) : QMainWindow(parent), resources(res){

    resources -> registerObserver(this);

    //imposta titolo e dimensione della finestra
    this->setWindowTitle("titolo finestra");
    this->setFixedSize(QSize(600, 400));

    //imposta il testo di informazione
    title = new QLabel("Classe che carica file di risorse e aggiorna una progress bar", this);
    title -> setGeometry(QRect(QPoint(100, 60), QSize(400, 100)));
    title -> setWordWrap(true);
    title -> setAlignment(Qt::AlignCenter);
    //QFont font = title -> font();
    //font.setPointSize(20);
    //title -> setFont(font);

    //imposta il bottone
    button = new QPushButton("carica risorse", this);
    button -> setGeometry(QRect(QPoint(215, 200), QSize(170, 30)));

    //imposta la progress bar
    progressBar = new QProgressBar(this);
    progressBar -> setGeometry(QRect(QPoint(150, 170), QSize(300, 30)));

    //imposta il campo di testo;
    text = new QTextEdit(this);
    text-> setGeometry(QRect(QPoint(50, 240), QSize(500, 140)));
    text -> setText("---> Ready to load resources!\n");
    text -> setReadOnly(true);

    progressBar -> setMinimum(0);
    progressBar -> setMaximum(100);
    progressBar -> setValue(0);

    //connette il bottone alla funzione che deve attivare
    connect(button, SIGNAL(released()), this ,SLOT(loadResources()));
}

MainWindow::~MainWindow() {
    resources -> removeObserver(this);
}

LoadResources* MainWindow::getResources() const {
    return resources;
}

