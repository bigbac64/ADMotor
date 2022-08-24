//
// Created by Antoine DESOBRY on 07/08/2022.
//

#ifndef ADMOTOR_COMPONENTTEST_H
#define ADMOTOR_COMPONENTTEST_H

#include "ADMotor/ADManagerComponent.h"

#include <stdlib.h>

class VoidClass{
public:
    VoidClass(){}
};

class VoidCmp: public ADComponent{
public:
    bool wasCall;
    VoidCmp(){wasCall = false;}
    void update() override {};
    void event(SDL_Event*evt) override {};
    void init() override {
        cout << "VoidCmp init " << endl;
        wasCall = true;
    };
    void close() override {};
    virtual ~VoidCmp() {};
};

class VoidDepend: public ADComponent{

public:
    bool wasCall;
    VoidDepend(){
        wasCall = false;
        addDependencyComponent<VoidCmp>();
    }
    void update() override {};
    void event(SDL_Event*evt) override {};
    void init() override {
        cout << "VoidDepend init " << endl;
        wasCall = true;
    };
    void close() override {};
    virtual ~VoidDepend() {};
};

class VoidOther: public ADComponent{
public:
    bool wasCall;
    VoidOther(){
        wasCall = false;
        addDependencyComponent<VoidCmp>();
    }
    void update() override {};
    void event(SDL_Event*evt) override {};
    void init() override {
        cout << "VoidOther init " << endl;
        wasCall = true;
    };
    void close() override {};
    virtual ~VoidOther() {};
};

#endif //ADMOTOR_COMPONENTTEST_H
