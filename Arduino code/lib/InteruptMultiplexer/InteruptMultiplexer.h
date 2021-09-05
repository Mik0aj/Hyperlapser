//
// Created by mikoaj on 04.09.2021.
//

#ifndef UNTITLED4_INTERUPTMULTIPLEXER_H
#define UNTITLED4_INTERUPTMULTIPLEXER_H


 class InteruptMultiplexer {
    static int *pinArray;
    static int pinArraySize;
    static int commonPin;
    static unsigned long lastFire;
public:
    InteruptMultiplexer(int *pinArray,int pinArraySize,int commonPin);
    int*givePinArray();
    static void press(int i);
    static void pressInterrupt();
    static void configureCommon();
    static void configureDistinct();

};

#endif //UNTITLED4_INTERUPTMULTIPLEXER_H
