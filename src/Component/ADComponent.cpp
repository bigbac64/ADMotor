//
// Created by Antoine DESOBRY on 21/07/2022.
//

#include "Component/ADComponent.h"
#include "ADMotor/ADManagerComponent.h"


ADComponent::ADComponent(){
    manager = nullptr;
}

/**
 *
 * @param mng ajoute le manager de composant
 */
void ADComponent::setManager(ADManagerComponent *mng) {
    manager = mng;
}

/**
 *
 * @return le manageur de composant
 */
ADManagerComponent *ADComponent::getManager() {
    return manager;
}


/**
 *
 * @return un vector de string des dépendance d'un composant
 **********************************************************************************************************************/
vector<string> ADComponent::getDependenciesComponent() const{
    return dependencies;
}

/**
 * destructeur du composant
 */
ADComponent::~ADComponent() {
    cout << "Component destroyManager" << endl;
    dependencies.clear();
}

/**
 * methode qui est appelé à la premiere frame du moteur
 **********************************************************************************************************************/
void ADComponent::init() {

}

/**
 * methode qui est appelé lors d'un évènement SDL
 **********************************************************************************************************************/
void ADComponent::event(SDL_Event *evt) {

}

/**
 * methode qui est appelé a chaque frame du moteur
 **********************************************************************************************************************/
void ADComponent::update() {

}

/**
 * methode qui doit être appelé a la fermeture fermeture d'un composant
 **********************************************************************************************************************/
void ADComponent::close() {

}

/**
 * methode qui est appelé a chaque actualisation graphique du moteur
 **********************************************************************************************************************/
void ADComponent::render(SDL_Renderer *render) {

}






