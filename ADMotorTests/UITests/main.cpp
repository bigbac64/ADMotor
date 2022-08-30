//
// Created by Antoine DESOBRY on 23/08/2022.
//
#include "SDLWindowTest.h"

int main(int argc, char **argv) {

    ADWindowTest();
    ADWindowManagerTest();
    ADApplicationTest(false);
    rotationTest(true);

    return 0;
}