//
// Created by mikoaj on 06.09.2021.
//

#ifndef ARDUINO_CODE_OBSERVER_H
#define ARDUINO_CODE_OBSERVER_H


class Subject;

class Observer {
public:
    void attachSubject(Subject *subject);
    virtual void onReceivedDataFromSubject(Subject*) = 0;
};
#endif //ARDUINO_CODE_OBSERVER_H
