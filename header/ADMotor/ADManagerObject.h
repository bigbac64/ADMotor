//
// Created by Antoine DESOBRY on 14/08/2022.
//

#ifndef ADMOTOR_ADMANAGEROBJECT_H
#define ADMOTOR_ADMANAGEROBJECT_H

#include "ADComposit.h"
#include "ADObject.h"

using namespace std;

class ADManagerObject : public ADComposit{
private:
    map<string, ADObject*> objects;

public:
    vector<ADObject*> getObjects() const;
    ADObject* getObject(string name) const;
    bool haveObject(string name) const;
    ADObject* makeObject(const string& name="");
    bool destroyObject(const string& name);

    void init() override;
    void update() override;
    void event(SDL_Event *) override;
    void render(SDL_Renderer *) override;
    void close() override;

    void destroyManager();
    ~ADManagerObject() override;
};

#endif //ADMOTOR_ADMANAGEROBJECT_H
