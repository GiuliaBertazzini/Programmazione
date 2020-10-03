//
// Created by giulia on 15/09/20.
//

#ifndef PROGRAMMAZIONE_CONCRETEOBSERVER_H
#define PROGRAMMAZIONE_CONCRETEOBSERVER_H

#include "Observer.h"
#include "LoadResources.h"

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(LoadResources *resources){
        res=resources;
        resources->registerObserver(this);
    }

    virtual ~ConcreteObserver(){
        res->removeObserver(this);
    }

    virtual void update() override {

    }


    LoadResources * res;
};

#endif //PROGRAMMAZIONE_CONCRETEOBSERVER_H
