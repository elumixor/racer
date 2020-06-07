//
// Created by vlado on 5/6/20.
//

#ifndef RACER_COMPONENT_H
#define RACER_COMPONENT_H


class Component {
public:
    virtual void on_init();
    virtual void on_update();
//    virtual void on_enable();
//    virtual void on_disable();
    virtual void on_destroy();
    virtual ~Component();
};


#endif //RACER_COMPONENT_H
