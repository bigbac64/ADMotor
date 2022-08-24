//
// Created by Antoine DESOBRY on 14/08/2022.
//
#include <gtest/gtest.h>
#include "ADMotor/ADObject.h"


TEST(ADObjectTest, make_and_delete){
    cout << "\ttest make_and_delete :" << endl;
    ADObject* adobj;

    adobj = new ADObject();

    EXPECT_TRUE(adobj != nullptr);

    delete adobj;

    cout << endl;
}

TEST(ADObjectTest, set_get_delete_tags){
    cout << "\ttest set_get_delete_tags :" << endl;
    ADObject* adobj;

    adobj = new ADObject();

    EXPECT_TRUE(adobj->getTags().size() == 0);

    adobj->addTag("tag1");
    adobj->addTag("tag2");

    EXPECT_TRUE(adobj->getTags().size() == 2);

    EXPECT_TRUE(adobj->haveTag("tag1"));

    EXPECT_FALSE(adobj->haveTag("tag3"));

    adobj->deleteTag("tag2");

    EXPECT_TRUE(adobj->getTags().size() == 1);

    EXPECT_FALSE(adobj->haveTag("tag2"));

    delete adobj;

    cout << endl;
}

TEST(ADObjectTest, set_get_name){
    cout << "\ttest set_get_name :" << endl;
    ADObject adobj;

    adobj = ADObject{"un nom"};

    EXPECT_TRUE(adobj.getName().compare("un nom") == 0);

    adobj.setName("other");

    EXPECT_TRUE(adobj.getName().compare("other") == 0);

    cout << endl;
}

TEST(ADObjectTest, rename){
    cout << "\ttest rename :" << endl;
    ADObject adobj;

    adobj.rename();

    EXPECT_TRUE(adobj.getName().compare("New_ADObject 1") == 0);

    adobj.rename();

    EXPECT_TRUE(adobj.getName().compare("New_ADObject 2") == 0);

}