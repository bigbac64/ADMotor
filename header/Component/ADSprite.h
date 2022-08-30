//
// Created by Antoine DESOBRY on 28/08/2022.
//

#ifndef ADMOTOR_ADSPRITE_H
#define ADMOTOR_ADSPRITE_H

#include <cmath>
#include "ADComponent.h"
#include "ADMotor/ADManagerComponent.h"
#include "ADTransform.h"
#include "SDL_image.h"

class ADSprite : public ADComponent{
private:
SDL_Texture *original;
SDL_Texture *texture;
SDL_Renderer *renderer;

public:
    ADSprite();
    bool loadSprite(char *file);
    void printTexture();

    void init() override;
    void render(SDL_Renderer *) override;
    void close() override;
};

#endif //ADMOTOR_ADSPRITE_H
