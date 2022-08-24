//
// Created by Antoine DESOBRY on 14/08/2022.
//
#include "ADMotor/ADManagerObject.h"

/**
 *
 * @return la liste des objets
 **********************************************************************************************************************/
vector<ADObject *> ADManagerObject::getObjects() const {
    vector<ADObject*> arrayObject;

    for (auto it : objects) {
        arrayObject.push_back(it.second);
    }

    return arrayObject;
}

/**
 *
 * @param name le nom de l'objet a récupérer
 * @return l'objet sélectionné
 **********************************************************************************************************************/
ADObject *ADManagerObject::getObject(string name) const {
    auto it =  objects.find(name);
    return it == objects.end() ? nullptr :  it->second;
}

/**
 *
 * @param name le nom de l'objet à tester
 * @return true si l'objet est present dans la liste d'objet
 **********************************************************************************************************************/
bool ADManagerObject::haveObject(string name) const {
    return objects.find(name) != objects.end();
}

/**
 * methode qui permet de créer un objet
 * @param name le nom de l'objet
 * @return le nouvel objet créé
 **********************************************************************************************************************/
ADObject *ADManagerObject::makeObject(const string& name) {
    ADObject* newObj;
    newObj = name.empty() ? new ADObject(): new ADObject(name);

    // si le nom est déjà présent dans la liste on renomme l'objet
    while(haveObject(newObj->getName())){
        newObj->rename();
    }

    objects[newObj->getName()] = newObj;
    newObj->init();

    return newObj;
}


/**
 *
 * @param name le nom de l'objet à detruire
 * @return true l'objet a été détruit correctement
 **********************************************************************************************************************/
bool ADManagerObject::destroyObject(const string& name) {
    if(!haveObject(name))
        return false;

    ADObject* delObj = objects[name];
    objects.erase(name);
    delete delObj;

    return true;
}

/**
 *
 **********************************************************************************************************************/
void ADManagerObject::init() {

}

/**
 * appele la fonction update de tous les objets de la liste
 **********************************************************************************************************************/
void ADManagerObject::update() {
    for (auto it : objects) {
        it.second->update();
    }
}

/**
 * appele la fonction event de tous les objets de la liste
 **********************************************************************************************************************/
void ADManagerObject::event(SDL_Event *evt) {
    for (auto it : objects) {
        it.second->event(evt);
    }
}

/**
 * appele la fonction render de tous les objets de la liste
 **********************************************************************************************************************/
void ADManagerObject::render(SDL_Renderer *rend) {
    for (auto it : objects) {
        it.second->render(rend);
    }
}

/**
 * appele la fonction close de tous les objets de la liste
 **********************************************************************************************************************/
void ADManagerObject::close() {
    for (auto it : objects) {
        it.second->close();
    }
}

/**
 * delete tout les objets de la liste
 */
void ADManagerObject::destroyManager() {
    for (const auto& it : objects) {
        ADObject* tmp = it.second;
        delete tmp;
    }
    objects.clear();
}

/**
 * delete tous les objets de la liste
 **********************************************************************************************************************/
ADManagerObject::~ADManagerObject() {
    destroyManager();

    cout << "ADManagerObject deleted" << endl;
}







