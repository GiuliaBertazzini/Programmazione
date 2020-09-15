//
// Created by giulia on 15/09/20.
//

#ifndef PROGRAMMAZIONE_SUBJECT_H
#define PROGRAMMAZIONE_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void attachObserver(Observer *obs) = 0;
    virtual void detachObserver(Observer *obs) = 0;
    virtual void notifyObserver()  = 0;
    virtual ~Subject() {};

};

#endif //PROGRAMMAZIONE_SUBJECT_H
