//
// Created by vlado on 5/6/20.
//

#ifndef RACER_BEHAVIOUR_H
#define RACER_BEHAVIOUR_H


class Behaviour {
public:
    virtual void on_init();
    virtual void on_update();
//    virtual void on_enable();
//    virtual void on_disable();
    virtual void on_destroy();
};


#endif //RACER_BEHAVIOUR_H
