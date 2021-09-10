//
// Created by mikoaj on 06.09.2021.
//

#ifndef ARDUINO_CODE_SUBJECT_H
#define ARDUINO_CODE_SUBJECT_H


#include "Observer.h"
// commented out code results in flexible array member error

class Observer;

class Subject {
protected:
    Observer *observer;
//    int *desiredIntValues[];
public:
    void registerObserver(Observer *obs);
    void unregisterObserver();
    virtual void notify() = 0;


//    int **getDesiredIntValues();
//    void setDesiredValues(int **desiredValues,int size);
};

#endif //ARDUINO_CODE_SUBJECT_H
