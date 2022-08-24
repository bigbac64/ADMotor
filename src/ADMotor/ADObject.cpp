//
// Created by Antoine DESOBRY on 14/08/2022.
//

#include <utility>

#include "ADMotor/ADObject.h"

/**
 * un nouvel objet doit avoir au moins un nom par defaut
 **********************************************************************************************************************/
ADObject::ADObject() {
    name = "New_ADObject";
}

/**
 * un nouvel objet avec un nom défini
 **********************************************************************************************************************/
ADObject::ADObject(string name) {
    ADObject::name = std::move(name);
}


/**
 *
 * @param newName le nom a donner a l'objet
 **********************************************************************************************************************/
void ADObject::setName(string newName) {
    name = std::move(newName);
}

/**
 *
 * @return le nom de l'objet
 */
string ADObject::getName() const{
    return name;
}

/**
 *
 * @return true si le tag existe dans la liste
 */
bool ADObject::haveTag(const string& tag) const{
    return find(tags.begin(), tags.end(), tag) != tags.end();
}


/**
 *
 * @param tag a ajouter dans la liste des tags le nom d'un tag si il n'existe pas
 **********************************************************************************************************************/
void ADObject::addTag(const string& tag) {
    if (haveTag(tag)) {
        return;
    }
    tags.push_back(tag);
}

/**
 *
 * @return la liste des tags
 **********************************************************************************************************************/
vector<string> ADObject::getTags() const{
    return tags;
}

ADObject::~ADObject() {
    tags.clear();
    cout << "Object " << name << " deleted" << endl;
}

/**
 *
 * @param tag le nom du tag à supprimer
 **********************************************************************************************************************/
void ADObject::deleteTag(const string& tag) {
    auto toDelete = find(tags.begin(), tags.end(),tag);
    tags.erase(toDelete);
}

/**
 * renomme l'objet en ajoutant un 1 ou en en faisant +1 si il existe déjà un chiffre à la fin du nom
 **********************************************************************************************************************/
void ADObject::rename() {
    string delimiter = " ";
    int pos = name.rfind(delimiter);
    string number = name.substr(pos + delimiter.length());

    int num = 0;
    try {
        num = stoi(number) + 1;
    } catch (exception e) {
        num = 1;
    }

    name = name.substr(0,pos) + delimiter + to_string(num);
}




