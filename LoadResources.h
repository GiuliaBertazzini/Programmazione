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
    virtual void attachObserver(Observer * obs) override;
    virtual void detachObserver(Observer *obs) override;
    virtual void notifyObserver() override;

private:
    list<Observer*> observers;
};
#endif //PROGRAMMAZIONE_LOADRESOURCES_H
