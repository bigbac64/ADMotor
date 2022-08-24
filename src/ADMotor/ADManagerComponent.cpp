//
// Created by user on 25/07/2022.
//
#include "ADMotor/ADManagerComponent.h"


ADManagerComponent::ADManagerComponent() = default;


/**
 *
 * @return la liste des composants
 **********************************************************************************************************************/
vector<ADComponent*> ADManagerComponent::getComponents() const{
    vector<ADComponent*> arrayComponents;

    auto it = components.begin();
    for (int i = 0; i < components.size(); ++i, ++it) {
        arrayComponents.push_back(it->second);
    }

    return arrayComponents;
}


/**
 * appele la methode init de tous les composants de la liste des composants
 **********************************************************************************************************************/
void ADManagerComponent::init() {
    for (auto it : components) {
        cout << "try" << endl;
        it.second->init();
    }
}

/**
 *
 * @return la map des composants
 **********************************************************************************************************************/
map<string, ADComponent *> ADManagerComponent::getComponentsMap() const{
    return components;
}


/**
 * appele la methode update de tous les composants de la liste des composants
 **********************************************************************************************************************/
void ADManagerComponent::update() {
    for (auto it : components) {
        it.second->update();
    }
}

/**
 * appele la methode close de tous les composants de la liste des composants
 **********************************************************************************************************************/
void ADManagerComponent::close() {
    for (auto it : components) {
        it.second->close();
    }
}

/**
 * appele la methode event de tous les composants de la liste des composants
 **********************************************************************************************************************/
void ADManagerComponent::event(SDL_Event *evt) {
    for (auto it : components) {
        it.second->event(evt);
    }
}

/**
 * appele la methode render de tous les composants de la liste des composants
 **********************************************************************************************************************/
void ADManagerComponent::render(SDL_Renderer *render) {
    for (auto it : components) {
        it.second->render(render);
    }
}

/**
 * delete tous les composants de la liste et les dépendences
 */
void ADManagerComponent::destroyManager(){
    for (const auto& it : components) {
        ADComponent* tmp = it.second;
        delete tmp;
    }

    nbDependencies.clear();
    components.clear();
}

/**
 *
 **********************************************************************************************************************/
ADManagerComponent::~ADManagerComponent() {
    destroyManager();

    cout << "ADManagerComponent deleted" << endl;
}