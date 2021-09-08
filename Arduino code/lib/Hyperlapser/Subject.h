//
// Created by mikoaj on 06.09.2021.
//

#ifndef ARDUINO_CODE_SUBJECT_H
#define ARDUINO_CODE_SUBJECT_H


#include "Observer.h"

class Observer;

class Subject {
protected:
    Observer *observer;
public:
    void registerObserver(Observer *obs);
    void unregisterObserver();
    virtual void notify() = 0;
    virtual int** getValues()=0;
};

#endif //ARDUINO_CODE_SUBJECT_H
