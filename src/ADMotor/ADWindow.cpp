//
// Created by AD on 25/07/2022.
//

#include "ADMotor/ADWindow.h"


/**
 * permet d'instancier une fenetre SDL avec le titre et la taille de la fenetre
 * @param title le titre de la fenetre
 * @param width la taille en largeur de la fenetre
 * @param height la taille en hauteur de la fenetre
 **********************************************************************************************************************/
ADWindow::ADWindow(string title, int width, int height) {
    ADWindow::title    = title;
    ADWindow::width    = width;
    ADWindow::height   = height;

    ADWindow::window   = nullptr;
    ADWindow::renderer = nullptr;
    ADWindow::id       = -1;
}

/**
 * permet d'instancier une fenetre SDL avec la taille de la fenetre
 * @param width la taille en largeur de la fenetre
 * @param height la taille en hauteur de la fenetre
 **********************************************************************************************************************/
ADWindow::ADWindow(int width, int height) {
    ADWindow::title    = "Default Window";
    ADWindow::width    = width;
    ADWindow::height   = height;

    ADWindow::window   = nullptr;
    ADWindow::renderer = nullptr;
}


/**
 * initialise la fenetre SDL
 **********************************************************************************************************************/
void ADWindow::init() {
    window = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            (int) width,
            (int) height,
            SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN
    );

    if(window == nullptr)
    {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        destroyWindow();
        return;
    }

    id = SDL_GetWindowID( window );

    // travail avec : SDL_RENDERER_SOFTWARE == Processeur, SDL_RENDERER_ACCELERATED = Carte graphique
    renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_SOFTWARE);

    if(renderer == nullptr){
        cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
        destroyWindow();
        return;
    }

    mode = ADW_MODE_ACTIVE;
}

/**
 * gère les evenements de la fenetre et envoie l'evenement au manager d'objet
 * @param evt l'evenement SDL
 **********************************************************************************************************************/
void ADWindow::event(SDL_Event *evt) {
    if( evt->type == SDL_WINDOWEVENT && evt->window.windowID == id ){
        switch( evt->window.event )
        {
                //Window closed
            case SDL_WINDOWEVENT_CLOSE:
                mode = ADW_MODE_CLOSE;
                break;

                //Window minimized
            case SDL_WINDOWEVENT_MINIMIZED:
                mode = ADW_MODE_INACTIVE;
                break;

                //Window restored
            case SDL_WINDOWEVENT_RESTORED:
                mode = ADW_MODE_ACTIVE;
                break;

                //Window resized
            case SDL_WINDOWEVENT_RESIZED:
                SDL_GetWindowSize(window, &width, &height);
                break;


            default:
                break;
        }
    }else{
        ADManagerObject::event(evt);
    }

}


/**
 *
 * @return le titre de la fenetre
 **********************************************************************************************************************/
string ADWindow::getTitle() {
    return title;
}



/**
 *
 * @return the window
 **********************************************************************************************************************/
SDL_Window *ADWindow::show() const {
    return window;
}

/**
 *
 * @return l'id de la fenetre
 **********************************************************************************************************************/
Uint32 ADWindow::getId() const {
    return id;
}

/**
 *
 * @return l'état de la fenetre
 **********************************************************************************************************************/
int ADWindow::getMode() const {
    return mode;
}


/**
 * mise à jour des objets et du rendu de la fenetre
 **********************************************************************************************************************/
void ADWindow::render(SDL_Renderer * rend) {
    if(renderer != nullptr)
        ADManagerObject::render(renderer);

    SDL_RenderPresent(renderer);
}

void ADWindow::close() {

}

/**
 * renomme la window en ajoutant un 1 ou en en faisant +1 si il existe déjà un chiffre à la fin du titre
 **********************************************************************************************************************/
void ADWindow::rename() {
    string delimiter = " ";
    int pos = title.rfind(delimiter);
    string number = title.substr(pos + delimiter.length());

    int num = 0;
    try {
        num = stoi(number) + 1;
        title = title.substr(0,pos) + delimiter + to_string(num);
    } catch (exception e) {
        num = 1;
        title = title + " " + to_string(num);
    }
}

/**
 * detruit correctement les éléments de la fenetre SDL,
 * si la fenêtre provient d’un manageur de fenêtre il est déconseillé d’appeler cette méthode
 **********************************************************************************************************************/
void ADWindow::destroyWindow() {
    if(renderer != nullptr)
        SDL_DestroyRenderer(renderer);

    if(window != nullptr)
        SDL_DestroyWindow(window);
}


ADWindow::~ADWindow() {
    destroyWindow();
    cout << "ADWindow " << title << " deleted" << endl;
}








