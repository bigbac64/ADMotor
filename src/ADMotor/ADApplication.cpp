//
// Created by Antoine DESOBRY on 23/08/2022.
//
#include "ADMotor/ADApplication.h"

ADApplication* ADApplication::instance = nullptr;

ADApplication::ADApplication() {
    isRunning = false;
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

    while (isRunning){
        if(windows.empty())
            isRunning = false;

        SDL_Event event;

        while (SDL_PollEvent(&event)){
            vector<ADWindow*> listToClose;

            for (auto it: windows) {

                it.second->event(&event);
                it.second->update();

                if(it.second->getMode() == ADW_MODE_CLOSE) {
                    listToClose.push_back(it.second);
                }
            }

            for(auto it : listToClose){
                closeWindow(it->getTitle());
            }
        }
    }
}

ADApplication::~ADApplication() {
    instance = nullptr;
    cout << "ADApplication deleted" << endl;
}



