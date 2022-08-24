//
// Created by Antoine DESOBRY on 07/08/2022.
//

#ifndef ADMOTOR_ADCOMPOSIT_H
#define ADMOTOR_ADCOMPOSIT_H

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <SDL.h>


/**
 * Class abstraite qui compose la structure des composants
 */
class ADComposit{
public:
    virtual void init() = 0;
    virtual void event(SDL_Event *) = 0;
    virtual void render(SDL_Renderer *) = 0;
    virtual void update() = 0;
    virtual void close() = 0;
    virtual ~ADComposit() { };
};

#endif //ADMOTOR_ADCOMPOSIT_H
