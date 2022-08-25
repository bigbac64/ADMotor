//
// Created by Antoine DESOBRY on 15/08/2022.
//

#ifndef ADMOTOR_ADMANAGERWINDOW_H
#define ADMOTOR_ADMANAGERWINDOW_H


#include "ADComposit.h"
#include "ADWindow.h"

using namespace std;

class ADManagerWindow : public ADComposit{
protected:
    map<string, ADWindow*> windows;
    ADManagerWindow() = default;

public:
    vector<ADWindow*> getWindows() const;
    ADWindow* getWindow(const string& name) const;
    bool haveWindow(const string& name) const;
    ADWindow* makeWindow(int width, int height, const string& name="");
    bool closeWindow(string name);

    void init() override;
    void update() override;
    void event(SDL_Event *) override;
    void render(SDL_Renderer *) override;
    void close() override;

    void destroyManager();
    ~ADManagerWindow() override;
};


#endif //ADMOTOR_ADMANAGERWINDOW_H
