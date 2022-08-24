//
// Created by Antoine DESOBRY on 21/07/2022.
//

#ifndef ADMOTOR_ADCOMPONENT_H
#define ADMOTOR_ADCOMPONENT_H

#include "ADMotor/ADComposit.h"

class ADManagerComponent;

using namespace std;

/**
 * Classe de composant pour gérer un objet du moteur
 */
class ADComponent : ADComposit {
private:
    vector<string> dependencies;
    ADManagerComponent* manager;

protected:
    template<class T>
    bool addDependencyComponent();

public:
    ADComponent();
    vector<string> getDependenciesComponent() const;

    void setManager(ADManagerComponent *mng);
    ADManagerComponent *getManager();

    void init() override;
    void event(SDL_Event *) override;
    void render(SDL_Renderer *) override;
    void update() override;
    void close() override;
    ~ADComponent() override;
};

/**
 * ajoute une dépendence à un composant
 *
 * @tparam T Une class enfant de ADComponent
 * @return si l'ajout du nom composant à dépendre a été fais correctement
 **********************************************************************************************************************/
template<class T>
bool ADComponent::addDependencyComponent() {
    if(is_base_of<ADComponent,T>::value) {
        dependencies.push_back((string) typeid(T).name());
        return true;
    }

    return false;
}



#endif //ADMOTOR_ADCOMPONENT_H
