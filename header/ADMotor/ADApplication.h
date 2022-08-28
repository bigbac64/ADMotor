//
// Created by Antoine DESOBRY on 23/08/2022.
//

#ifndef ADMOTOR_ADAPPLICATION_H
#define ADMOTOR_ADAPPLICATION_H

#include "ADManagerWindow.h"

/**
 * ADApplication permet d'executer le moteur
 *
 * intègre un modèle de singleton pour qu’elle puissent être accessible de n’importe où et être instancié qu’une seul fois par lancement,
 * ATTENTION il faut penser a delete l’instance a la fin du programme
 *
 */
class ADApplication : public ADManagerWindow{
private:
    int fpsUpdate;
    int fpsRender;
    bool isRunning;
    static ADApplication* instance;
    ADApplication();
public:
    static ADApplication* getApplication();
    void setFpsUpdate(int);
    int getFpsUpdate() const;
    void setFpsRender(int);
    int getFpsRender() const;
    static int fpsToMs(int) ;
    void run();
    ~ADApplication() override;


};

#endif //ADMOTOR_ADAPPLICATION_H
