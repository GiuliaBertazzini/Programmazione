//
// Created by giulia on 15/09/20.
//

#ifndef PROGRAMMAZIONE_SUBJECT_H
#define PROGRAMMAZIONE_SUBJECT_H

#include "Observer.h"

class Subject {
public:

    virtual void registerObserver(Observer *obs) = 0;
    virtual void removeObserver(Observer *obs) = 0;
    virtual void notifyObservers() const = 0;

protected:
    virtual ~Subject() = default;

};

#endif //PROGRAMMAZIONE_SUBJECT_H
