//
// Created by mikoaj on 06.09.2021.
//

#include <string.h>
#include "Subject.h"
#include "Observer.h"

void Subject::unregisterObserver() {
    observer = nullptr;
}

void Subject::registerObserver(Observer *obs) {
    observer = obs;
}


//int **Subject::getDesiredIntValues() {
//    return desiredIntValues;
//}
//
//void Subject::setDesiredValues(int **desiredValues,int size ) {
//
//    memcpy(&desiredIntValues,&desiredValues,  size);
//}

