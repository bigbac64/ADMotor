//
// Created by Antoine DESOBRY on 28/08/2022.
//
#include "Component/ADSprite.h"

ADSprite::ADSprite() {
    addDependencyComponent<ADTransform>();
    original = nullptr;
    texture = nullptr;
    renderer = nullptr;
}

bool ADSprite::loadSprite(char *file) {
    if(renderer == nullptr)
        return false;

    SDL_Surface* tmp = IMG_Load(file);
    if(!tmp)
    {
        cout <<"Erreur de chargement de l'image : " << SDL_GetError() << endl;
        return false;
    }
    original = SDL_CreateTextureFromSurface(renderer,tmp);
    SDL_FreeSurface(tmp);
    return true;
}

void ADSprite::printTexture() {
    if(renderer == nullptr || original == nullptr)
        return;

    Point3D pos = getManager()->getComponent<ADTransform>()->getPostion();
    Point3D rot = getManager()->getComponent<ADTransform>()->getRotation();
    Point3D sca = getManager()->getComponent<ADTransform>()->getScale();

    int w,h;
    SDL_QueryTexture(original, NULL, NULL, &w, &h);

    // positionnement du sprite par rapport au centre du sprite
    SDL_Rect rect = SDL_Rect{pos.x - (w * sca.x)/2,pos.y - (h * sca.y)/2, w * sca.x, h * sca.y};

    //SDL_RenderCopy(renderer, original, NULL, &rect);
    SDL_RenderCopyEx(renderer, original, NULL, &rect, rot.z, NULL, SDL_FLIP_NONE);

}

void ADSprite::init() {
}

void ADSprite::render(SDL_Renderer *rend) {
    if(renderer == nullptr)
        renderer = rend;

    printTexture();
}

void ADSprite::close() {
    SDL_DestroyTexture(original);
    SDL_DestroyTexture(texture);
}





