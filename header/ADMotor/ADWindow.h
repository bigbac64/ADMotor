//
// Created by AD on 25/07/2022.
//

#ifndef ADMOTOR_ADWINDOW_H
#define ADMOTOR_ADWINDOW_H

#define ADW_MODE_ACTIVE 1
#define ADW_MODE_INACTIVE 2
#define ADW_MODE_CLOSE 3

#include <SDL.h>
#include "ADManagerObject.h"

/**
 * les fenêtre SDL sont gérer par la classe ADWindow,
 * chaque fenêtre gère les objets de la scène
 */
class ADWindow : public ADManagerObject{
private:
    string        title;
    Uint32        id;
    int           width;
    int           height;
    int           mode;
    SDL_Window   *window;
    SDL_Renderer *renderer;


public:
    ADWindow(string title, int width, int height);
    ADWindow(int width, int height);
    SDL_Window *show() const;
    Uint32 getId() const;
    int getMode() const;
    string getTitle();
    void destroyWindow();
    ~ADWindow() override;

    void init() override;
    void event(SDL_Event *) override;
    void render(SDL_Renderer *) override;
    void close() override;
    void rename();

};

#endif //ADMOTOR_ADWINDOW_H
