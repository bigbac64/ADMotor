//
// Created by Antoine DESOBRY on 23/08/2022.
//
#include "ADMotor/ADApplication.h"

ADApplication* ADApplication::instance = nullptr;

ADApplication::ADApplication() {
    isRunning = false;
    fpsUpdate = 30;
    fpsRender = 60;
}

/**
 *
 * @return l'instance de application moteur
 */
ADApplication* ADApplication::getApplication() {
    if (instance == nullptr)
        instance = new ADApplication();

    return instance;
}


/**
 * démarre la boucle infini du moteur si au moins une fenetre existe
 */
void ADApplication::run() {
    isRunning = true;

    Uint64 timingUpdate = SDL_GetTicks64();
    Uint64 timingRender = SDL_GetTicks64();

    while (isRunning){
        if(windows.empty())
            isRunning = false;

        SDL_Event event;

        while (SDL_PollEvent(&event)){
            vector<ADWindow*> listToClose;

            for (auto it: windows) {

                it.second->event(&event);

                if(it.second->getMode() == ADW_MODE_CLOSE) {
                    listToClose.push_back(it.second);
                }
            }

            for(auto it : listToClose){
                closeWindow(it->getTitle());
            }
        }

        // update actif tous les 30 fps par defaut
        if(SDL_GetTicks64() >= timingUpdate + fpsToMs(fpsUpdate)){
            if(SDL_GetTicks64() > timingUpdate + fpsToMs(fpsUpdate) * 2)
                cout << "WARN : Baisse de performance update" << endl;

            for (auto it: windows) {
                it.second->update();
            }
            timingUpdate = SDL_GetTicks64();
        }

        // render actif tous les 60 fps par defaut
        if(SDL_GetTicks64() >= timingRender + fpsToMs(fpsRender)){
            if(SDL_GetTicks64() >= timingRender + fpsToMs(fpsRender) * 2)
                cout << "WARN : Baisse de performance render" << endl;

            for (auto it: windows) {
                it.second->render(nullptr);
            }
            timingRender = SDL_GetTicks64();
        }
    }
}

ADApplication::~ADApplication() {
    instance = nullptr;
    cout << "ADApplication deleted" << endl;
}

void ADApplication::setFpsUpdate(int fps) {
    if(fps > 0)
        fpsUpdate = fps;
}

int ADApplication::getFpsUpdate() const {
    return fpsUpdate;
}

void ADApplication::setFpsRender(int fps) {
    if(fps > 0)
        fpsRender = fps;
}

int ADApplication::getFpsRender() const {
    return fpsRender;
}

int ADApplication::fpsToMs(int fps) {
    return 1000/fps;
}



