//
// Created by Antoine DESOBRY on 14/08/2022.
//
#include <gtest/gtest.h>
#include "ADMotor/ADManagerObject.h"

TEST(ADManagerObjectTest, make_and_delete){
    cout << "\ttest make_and_delete" << endl;

    ADManagerObject* admngobj;

    admngobj = new ADManagerObject();

    EXPECT_TRUE(admngobj != nullptr);

    delete admngobj;

    cout << endl;
}

TEST(ADManagerObjectTest, instanciate_destroy_object){
    cout << "\ttest instanciate_destroy_object" << endl;

    ADManagerObject* admngobj;
    admngobj = new ADManagerObject();
    ADObject* adobj;
    ADObject* adobj2;

    EXPECT_TRUE(admngobj->getObjects().size() == 0);

    adobj = admngobj->makeObject();

    EXPECT_TRUE(admngobj->getObjects().size() == 1);

    adobj2 = admngobj->makeObject();

    cout << "name : " <<  adobj2->getName() << endl;

    EXPECT_TRUE(admngobj->getObjects().size() == 2);
    cout << "name : " <<  admngobj->getObjects()[0]->getName() << endl;

    EXPECT_TRUE(admngobj->destroyObject(adobj->getName()));

    EXPECT_TRUE(admngobj->getObjects().size() == 1);

    EXPECT_FALSE(admngobj->destroyObject("empty"));

    EXPECT_TRUE(admngobj->getObjects().size() == 1);

    delete admngobj;

    cout << endl;
}

TEST(ADManagerObjectTest, have_object){
    cout << "\ttest have_object" << endl;

    ADManagerObject* admngobj;
    admngobj = new ADManagerObject();
    ADObject* adobj;
    adobj = admngobj->makeObject();
    ADObject* adobj2;
    adobj2 = new ADObject("pouet");

    EXPECT_TRUE(admngobj->haveObject(adobj->getName()));

    EXPECT_FALSE(admngobj->haveObject(adobj2->getName()));

    EXPECT_FALSE(admngobj->haveObject("none"));

    delete admngobj;

    cout << endl;
}

TEST(ADManagerObjectTest, get_object){
    cout << "\ttest get_object" << endl;

    ADManagerObject* admngobj;
    admngobj = new ADManagerObject();

    ADObject* adobj;
    adobj = admngobj->makeObject();

    EXPECT_TRUE(admngobj->getObject(adobj->getName()) == adobj);

    EXPECT_TRUE(admngobj->getObject("none") == nullptr);

    delete admngobj;

    cout << endl;
}