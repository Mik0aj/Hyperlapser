//
// Created by mikoaj on 06.09.2021.
//

#include "Observer.h"
#include "Subject.h"

void Observer::attachSubject(Subject *subject) {
    subject->registerObserver(this);
}