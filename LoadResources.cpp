//
// Created by giulia on 15/09/20.
//

#include <iostream>
#include "LoadResources.h"
#include <thread>
#include <chrono>

LoadResources::LoadResources() {
    numberResources = 0;
    loaded = false;
}

void LoadResources::registerObserver(Observer *obs) {
    observers.push_back(obs); //inserisce in fondo alla lista
}

void LoadResources::removeObserver(Observer *obs) {
    observers.remove(obs);
}

void LoadResources::notifyObservers() const {
    for(const auto &itr : observers){
        itr -> update();              //scorro tutti gli osservatori registrati e chiamo update
    }
}

bool LoadResources::loadedFile() const {
    return loaded;
}

void LoadResources::setLoad(bool l) {
    loaded=l;
}

int LoadResources::getFileSize() const {
    return filesize;
}

int LoadResources::getNumberResources() const {
    return numberResources;
}

const QString & LoadResources::getFileName() {
    return filename;
}


void LoadResources::load(std::vector<string> &filenames) {
    try {
        numberResources = filenames.size();
        if (numberResources==0) {
            throw std::runtime_error("Nessuna risorsa");
        }
    } catch (std::runtime_error& e) {
        std::cerr<<e.what()<<std::endl;
    }
    for (auto &it : filenames) {
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
        handleFile(it);

    }
}

void LoadResources::handleFile(string it) {
    try {
        File file(it);
        filename = QString(it.c_str());  //converte nome in Unicode
        filesize = file.getFileSize();
        setLoad(true);
        notifyObservers();

    } catch (std::runtime_error &e) {
        filename = QString(it.c_str());
        setLoad(false);
        notifyObservers();

    } catch (...) {
        std:cerr<< "Unknown exception" << std::endl;
    }
}
