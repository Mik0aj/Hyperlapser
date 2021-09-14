//
// Created by mikoaj on 04.09.2021.
//

#ifndef UNTITLED4_STATE_H
#define UNTITLED4_STATE_H


class Hyperlapser;
class State {
public:
    State(Hyperlapser* newOwner);
    virtual ~State();
    virtual void upButton() = 0;
    virtual void downButton() =0;
    virtual void confirmButton() = 0;
    virtual int returnStateId()=0;
protected:
    Hyperlapser* owner;
};


#endif //UNTITLED4_STATE_H

