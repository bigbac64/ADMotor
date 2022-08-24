//
// Created by Antoine DESOBRY on 26/07/2022.
//

#include <gtest/gtest.h>
#include "Component/ADComponent.h"
#include "ADMotor/ADManagerComponent.h"
#include "ComponentTest.h"
#include <type_traits>


template<class T>
testing::AssertionResult instanciate() {

    if(std::is_abstract<T>())
        return testing::AssertionFailure() << typeid(T).name() << " is abstract";

    return testing::AssertionSuccess();
}


TEST(ADComponentTest, Instanciate_Component){
    EXPECT_TRUE(instanciate<ADComponent>()) << " ADComponent is not abstract";
}

TEST(ADComponentTest, Instanciate_Component_Manager){
    EXPECT_TRUE(instanciate<ADManagerComponent>()) << " ADManagerComponent is not abstract";
}

TEST(ADComponentTest, Add_Dependencie){
    VoidDepend v;
    vector<string> elem = v.getDependenciesComponent();
    int len = elem.size();
    EXPECT_TRUE(len == 1) << " dependencie added";
}

TEST(ADComponentTest, Get_Component){
    ADManagerComponent admc;
    admc.addComponent<VoidCmp>();
    admc.addComponent<VoidOther>();

    EXPECT_TRUE(admc.getComponent<VoidCmp>()->getManager()->getComponent<VoidOther>() == admc.getComponent<VoidOther>());
}
