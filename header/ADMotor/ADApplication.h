//
// Created by Antoine DESOBRY on 23/08/2022.
//

#ifndef ADMOTOR_ADAPPLICATION_H
#define ADMOTOR_ADAPPLICATION_H

#include "ADManagerWindow.h"

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
