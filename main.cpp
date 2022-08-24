#include <iostream>
#include <SDL.h>
#include "header/ADMotor/ADWindow.h"



int main(int argc, char* args[]) {
    ADWindow window("ADMotor", 600, 400);

    if(! window.init())
        return SDL_LASTERROR;

    window.show();
    window.update();

    window.run();

    return 0;
}
