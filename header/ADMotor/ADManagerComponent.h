//
// Created by user on 25/07/2022.
//

#ifndef ADMOTOR_ADMANAGERCOMPONENT_H
#define ADMOTOR_ADMANAGERCOMPONENT_H

#include "ADComposit.h"
#include "Component/ADComponent.h"


using namespace std;

class ADManagerComponent: public ADComposit{
private:
    map<string, ADComponent*> components;
    map<string, int> nbDependencies;

public:
    ADManagerComponent();
    vector<ADComponent*> getComponents()const;
    map<string, ADComponent*> getComponentsMap() const;

    template<class T> ADComponent *getComponent() const;
    template<class T> bool         addComponent();
    template<class T> bool         removeComponent();
    template<class T> bool         haveComponent() const;

    void init() override;
    void event(SDL_Event *) override;
    void render(SDL_Renderer *) override;
    void update() override;
    void close() override;

    void destroyManager();
    ~ADManagerComponent() override;
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * renvoie le composant appelé si il existe sinon null
 *
 * @tparam T Une class enfant de ADComponent
 * @return Le composant appelé
 **********************************************************************************************************************/
template<class T>
ADComponent *ADManagerComponent::getComponent() const{
    string classname = typeid(T).name();

    // si la class n'est pas dans components
    if(components.find(classname) == components.end()){
        cout << "Component " + classname + " doesn't exist, you can't get it" << endl;
        return nullptr;
    }

    return components.find(classname)->second;
}

/**
 * ajoute un composant
 *  -  si il n'est pas déjà présent dans la liste des composants
 *  -  si une des dépendances du nouveau composant n'est pas présentent dans la liste des composants
 *  -  si une dépendance existe, ajoute de 1 le nombre du composant lié
 *
 * @tparam T Une class enfant de ADComponent
 * @return si l'ajout d'un composant a été fait correctement
 **********************************************************************************************************************/
template<class T>
bool ADManagerComponent::addComponent() {
    string classname = typeid(T).name();

    // si la class est dans components
    if(components.find(classname) != components.end()){
        cout << "Component " + classname + " already exist, you can't add it" << endl;
        return false;
    }


    T *component = new T();
    vector<string> dependenciesName = component->getDependenciesComponent();
    unsigned int len = dependenciesName.size();
    for (int i=0; i < len; i++){

        // si les dependance du nouveau composant ne sont pas présente dans la liste
        if(components.find(dependenciesName[i]) == components.end()){
            std::cout << "Component " << dependenciesName[i] << " doesn't exist, " + classname +" need this component to work" << endl;
            delete component;
            return false;
        }

        // ajoute les composants que dépend le nouveau composant dans la liste des dépendances
        if(nbDependencies.find(dependenciesName[i]) != nbDependencies.end())
            nbDependencies[dependenciesName[i]] += 1;
        else
            nbDependencies[dependenciesName[i]] = 1;
    }

    component->setManager(this);
    components[classname] = component;

    return true;
};


/**
 * supprime un composant :
 *  -  si il existe dans la liste des composants
 *  -  si il n'appartient pas à la liste des dépendances;
 *  -  suppresion des liaisons dépendantes
 *
 * @tparam T Une class enfant de ADComponent
 * @return si la supression d'un composant a été fait correctement
 **********************************************************************************************************************/
template<class T>
bool ADManagerComponent::removeComponent() {
    string classname = typeid(T).name();

    // si la class n'est pas dans la liste des composants
    if(components.find(classname) == components.end()){
        cout << "Component " + classname + " doesn't exist, you can't remove it" << endl;
        return false;
    }

    ADComponent *component = getComponent<T>();

    // si le composant est lié a une dépendance
    if(nbDependencies.find(classname) != nbDependencies.end()){
        std::cout << "Component " << classname << " link to a dependence, you can't remove it" << endl;
        return false;
    }

    // suppresion des liaisons dépendantes
    vector<string> dependenciesName = component->getDependenciesComponent();
    unsigned int len = dependenciesName.size();

    for (int i=0; i < len; i++){
        if (nbDependencies.find(dependenciesName[i]) != nbDependencies.end())
            nbDependencies[dependenciesName[i]] -= 1;

        if (nbDependencies[dependenciesName[i]] <= 0){
            nbDependencies.erase(dependenciesName[i]);
        }
    }

    components.erase(classname);
    delete component;
    return true;
};


/**
 *
 * @tparam T
 * @return
 **********************************************************************************************************************/
template<class T>
bool ADManagerComponent::haveComponent() const {
    string classname = typeid(T).name();

    return components.find(classname) != components.end();
};


#endif //ADMOTOR_ADMANAGERCOMPONENT_H
