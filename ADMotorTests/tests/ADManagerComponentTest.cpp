//
// Created by Antoine DESOBRY on 27/07/2022.
//

#include <gtest/gtest.h>
#include "ADMotor/ADManagerComponent.h"

#include "ComponentTest.h"


TEST(ADManagerComponentTest, Make_Component_Manager){
    ADManagerComponent* adcm;

    adcm = new ADManagerComponent();

    EXPECT_TRUE(adcm != nullptr);

    EXPECT_TRUE(adcm->getComponentsMap().empty());
}

TEST(ADManagerComponentTest, Manage_Component){
    ADManagerComponent adcm;

    EXPECT_TRUE(adcm.getComponent<VoidClass>() == nullptr);

    EXPECT_FALSE(adcm.addComponent<VoidDepend>()) << "dependance work";

    EXPECT_TRUE(adcm.getComponentsMap().empty());

    EXPECT_TRUE(adcm.addComponent<VoidCmp>());

    EXPECT_TRUE(adcm.getComponentsMap().size() == 1);

    EXPECT_FALSE(adcm.getComponent<VoidCmp>() == nullptr);

    EXPECT_TRUE(adcm.addComponent<VoidDepend>());

    EXPECT_TRUE(adcm.getComponentsMap().size() == 2);

    EXPECT_FALSE(adcm.getComponent<VoidDepend>() == nullptr);

    EXPECT_FALSE(adcm.addComponent<VoidDepend>());
}

TEST(ADManagerComponentTest, Destroy_Component){
    auto *adcm = new ADManagerComponent();
    adcm->addComponent<VoidCmp>();

    delete adcm;
}

TEST(ADManagerComponentTest, Get_List_Component){
    ADManagerComponent adcm;
    adcm.addComponent<VoidCmp>();
    adcm.addComponent<VoidDepend>();

    vector<ADComponent*> l = adcm.getComponents();

    EXPECT_TRUE(l.size() == 2);

}

TEST(ADManagerComponentTest, Remove_Component){
    ADManagerComponent adcm;
    adcm.addComponent<VoidCmp>();
    adcm.addComponent<VoidDepend>();

    EXPECT_FALSE(adcm.removeComponent<VoidCmp>());

    EXPECT_TRUE(adcm.removeComponent<VoidDepend>());

    EXPECT_TRUE(adcm.getComponents().size() == 1);

    EXPECT_TRUE(adcm.removeComponent<VoidCmp>());

    EXPECT_TRUE(adcm.getComponents().empty());

}

TEST(ADManagerComponentTest, Have_Component){
    ADManagerComponent adcm;
    adcm.addComponent<VoidCmp>();

    EXPECT_TRUE(adcm.haveComponent<VoidCmp>());

    EXPECT_FALSE(adcm.haveComponent<VoidDepend>());

    adcm.addComponent<VoidDepend>();

    EXPECT_TRUE(adcm.haveComponent<VoidDepend>());

    adcm.removeComponent<VoidDepend>();

    EXPECT_FALSE(adcm.haveComponent<VoidDepend>());
}

TEST(ADManagerComponentTest, init_all_Component){
    ADManagerComponent adcm;
    adcm.addComponent<VoidCmp>();
    adcm.addComponent<VoidOther>();

    adcm.init();

    EXPECT_TRUE(((VoidCmp*) adcm.getComponent<VoidCmp>())->wasCall);

    EXPECT_TRUE(((VoidOther*) adcm.getComponent<VoidOther>())->wasCall);

}