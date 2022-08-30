//
// Created by Antoine DESOBRY on 23/08/2022.
//

#include "SDLWindowTest.h"

void ADWindowTest(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        throw;
    }

    ADWindow win(600,400);
    win.init();
    SDL_Window* e = win.show();

    if( e != nullptr)
        cout << "ADWindowTest init window test OK." << endl;
    else
        cout << "ADWindowTest init window test KO! " << endl;

    if( win.getId() != -1)
        cout << "ADWindowTest id=" << win.getId() << " test OK." << endl;
    else
        cout << "ADWindowTest id=-1 test KO! " << endl;

    win.rename();

    if( win.getTitle() == "Default Window 1")
        cout << "ADWindowTest rename test OK." << endl;
    else
        cout << "ADWindowTest rename test KO! " << endl;

    win.rename();

    if( win.getTitle() == "Default Window 2")
        cout << "ADWindowTest rename test OK." << endl;
    else
        cout << "ADWindowTest rename test KO! " << endl;


    SDL_Quit();
}

void ADWindowManagerTest(){
    ADApplication* adap = ADApplication::getApplication();
    adap->init();
    ADWindow* ad1 = adap->makeWindow(400,200, "dodo");

    if( ad1->show() != nullptr)
        cout << "ADWindowManagerTest init window test OK." << endl;
    else
        cout << "ADWindowManagerTest init window test KO! " << endl;

    if( ad1->getId() != -1)
        cout << "ADWindowManagerTest id=" << ad1->getId() << " test OK." << endl;
    else
        cout << "ADWindowManagerTest id=-1 test KO! " << endl;

    ADWindow* ad2 = adap->makeWindow(400,200, "dodo");

    if( ad2->show() != nullptr)
        cout << "ADWindowManagerTest init window test OK." << endl;
    else
        cout << "ADWindowManagerTest init window test KO! " << endl;

    if( ad2->getId() != -1)
        cout << "ADWindowManagerTest id=" << ad2->getId() << " test OK." << endl;
    else
        cout << "ADWindowManagerTest id=-1 test KO! " << endl;

    if(!adap->getWindows().empty())
        cout << "ADWindowManagerTest windows not empty test OK." << endl;
    else
        cout << "ADWindowManagerTest windows is empty test KO! " << endl;

    if(adap->getWindow(ad2->getTitle()) == ad2)
        cout << "ADWindowManagerTest window is same test OK." << endl;
    else
        cout << "ADWindowManagerTest windows isn't same test KO! " << endl;

    delete adap;

}

void ADApplicationTest(bool run){
    ADApplication* adap = ADApplication::getApplication();
    adap->makeWindow(600,400);
    adap->makeWindow(550,350);
    adap->makeWindow(500,300);
    adap->makeWindow(450,250);
    adap->makeWindow(400,200);

    if(adap->getWindows().size() == 5)
        cout << "ADApplicationTest windows size is 5 test OK." << endl;
    else
        cout << "ADApplicationTest windows size is not 5 test KO! " << endl;

    if(run)
        adap->run();

    delete adap;
}

class TestSprite : public ADSprite{
private:
    bool translate = false;
    float speed = 0;
public:
    void event(SDL_Event* evt) override{
        if(evt->type == SDL_KEYDOWN && evt->key.keysym.sym == SDLK_a) {
            cout << "keydowned" << endl;
            loadSprite("D:\\PROGRAMMATION\\C++Project\\ADMotor\\sprites\\test.png");
        }

        if(evt->type == SDL_KEYDOWN && evt->key.keysym.sym == SDLK_UP) {
            translate = true;
        }

        if(evt->type == SDL_KEYUP && evt->key.keysym.sym == SDLK_UP) {
            translate = false;
        }
    }

    void update() override{
        if(translate) {
            Point3D rot = getManager()->getComponent<ADTransform>()->getRotation();
            speed += 0.1;
            rot.z += speed;
            getManager()->getComponent<ADTransform>()->setRotation(rot);
        }
    }
};

void rotationTest(bool run){
    ADApplication *adap = ADApplication::getApplication();
    ADWindow *adw = adap->makeWindow(600,400);

    ADObject *ado = adw->makeObject("test");
    ado->addComponent<ADTransform>();
    ado->getComponent<ADTransform>()->setPostion(Point3D{110,110,0});
    ado->getComponent<ADTransform>()->setRotation(Point3D{0,0,10});
    ado->addComponent<TestSprite>();

    if(run)
        adap->run();

    delete adap;
}