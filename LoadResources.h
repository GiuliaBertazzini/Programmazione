//
// Created by giulia on 15/09/20.
//

#ifndef PROGRAMMAZIONE_LOADRESOURCES_H
#define PROGRAMMAZIONE_LOADRESOURCES_H

#include "Subject.h"
#include "Observer.h"
#include <list>
using namespace std;

class LoadResources : public Subject {
public:
    LoadResources();
    virtual void registerObserver(Observer * obs) override;
    virtual void removeObserver(Observer *obs) override;
    virtual void notifyObservers() const override;

private:
    list<Observer*> observers;  //puntatori a classe base perchè non so quali saranno quelli concreti
    int numberResources;
};
#endif //PROGRAMMAZIONE_LOADRESOURCES_H
