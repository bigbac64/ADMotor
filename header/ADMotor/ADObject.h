//
// Created by Antoine DESOBRY on 14/08/2022.
//

#ifndef ADMOTOR_ADOBJECT_H
#define ADMOTOR_ADOBJECT_H

#include "ADManagerComponent.h"
#include <algorithm>


class ADObject : public ADManagerComponent{
private:
    string         name;
    vector<string> tags;
public:
    ADObject();
    explicit ADObject(string name);
    void setName(string newName);
    string getName() const;
    void addTag(const string& tag);
    vector<string> getTags() const;
    void deleteTag(const string& tag);
    bool haveTag(const string&) const;
    void rename();
    ~ADObject() override;

};

#endif //ADMOTOR_ADOBJECT_H
