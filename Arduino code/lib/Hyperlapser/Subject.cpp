//
// Created by mikoaj on 06.09.2021.
//

#include "Subject.h"
#include "Observer.h"

void Subject::unregisterObserver() {
    observer = nullptr;
}

void Subject::registerObserver(Observer *obs) {
    observer = obs; //we will only allow one observer
}