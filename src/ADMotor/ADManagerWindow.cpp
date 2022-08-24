//
// Created by Antoine DESOBRY on 15/08/2022.
//

#include "ADMotor/ADManagerWindow.h"


/**
 *
 * @return la liste des objets
 **********************************************************************************************************************/
vector<ADWindow *> ADManagerWindow::getWindows() const {
    vector<ADWindow*> arrayWindow;

    for (auto it : windows) {
        arrayWindow.push_back(it.second);
    }

    return arrayWindow;
}

/**
 * initialise SDL
 **********************************************************************************************************************/
void ADManagerWindow::init() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        throw ;
    }
}

/**
 *
 * @param name le nom de l'objet a récupérer
 * @return l'objet sélectionné
 **********************************************************************************************************************/
ADWindow *ADManagerWindow::getWindow(const string& name) const {
    auto it =  windows.find(name);
    return it == windows.end() ? nullptr :  it->second;
}

/**
 *
 * @param name le nom de l'objet à tester
 * @return true si l'objet est present dans la liste d'objet
 **********************************************************************************************************************/
bool ADManagerWindow::haveWindow(const string& name) const {
    return windows.find(name) != windows.end();
}

/**
 * methode qui permet de créer une fenetre
 * @param title le nom de la fenetre
 * @return la nouvelle fenetre créé ou nullptr si l'initialisation a échoué
 **********************************************************************************************************************/
ADWindow *ADManagerWindow::makeWindow(int width, int height, const string& name) {
    ADWindow* newWin;
    if (!name.empty()) {
        newWin = new ADWindow(name, width, height);
    } else {
        newWin = new ADWindow(width, height);
    }


    while(haveWindow(newWin->getTitle())){
        newWin->rename();
    }

    windows[newWin->getTitle()] = newWin;
    newWin->init();

    if(newWin->show() == nullptr){
        cout << "la fenetre " << newWin->getTitle() << " n'a pas été créée" << endl;
        delete newWin;
        return nullptr;
    }

    return newWin;
}


/**
 *
 * @param name le nom de l'objet à detruire
 * @return true l'objet a été détruit correctement
 **********************************************************************************************************************/
bool ADManagerWindow::closeWindow(string name) {
    if(!haveWindow(name))
        return false;

    ADWindow* delWin = windows[name];
    windows.erase(name);
    delete delWin;

    return true;
}


/**
 * appele la fonction update de toutes les fenetres de la liste
 **********************************************************************************************************************/
void ADManagerWindow::update() {
    for (auto it : windows) {
        it.second->update();
    }
}

/**
 * appele la fonction event de toutes les fenetres de la liste
 **********************************************************************************************************************/
void ADManagerWindow::event(SDL_Event *evt) {
    for (auto it : windows) {
        it.second->event(evt);
    }
}




/**
 * appele la fonction close de toutes les fenetres de la liste
 **********************************************************************************************************************/
void ADManagerWindow::close() {
    for (auto it : windows) {
        it.second->close();
    }
}

/**
 * delete toutes les fenetres de la liste
 **********************************************************************************************************************/
void ADManagerWindow::destroyManager() {
    for (auto it : windows) {
        ADWindow* tmp = it.second;
        delete tmp;
    }
    windows.clear();
    SDL_Quit();
}



ADManagerWindow::~ADManagerWindow() {
    destroyManager();
    cout << "ADManagerWindow deleted" << endl;
}




