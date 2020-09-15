//
// Created by giulia on 15/09/20.
//

#ifndef PROGRAMMAZIONE_OBSERVER_H
#define PROGRAMMAZIONE_OBSERVER_H

class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer(){};
};

#endif //PROGRAMMAZIONE_OBSERVER_H
