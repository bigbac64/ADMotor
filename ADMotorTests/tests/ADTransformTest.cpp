//
// Created by Antoine DESOBRY on 28/08/2022.
//
#include <gtest/gtest.h>
#include "Component/ADTransform.h"

TEST(ADTransformTest, init_and_delete){
    ADTransform* adt = new ADTransform();
    adt->init();
    EXPECT_TRUE(adt != nullptr);
    delete adt;

}

TEST(ADTransformTest, get_and_set){
    ADTransform adt;
    adt.init();

    EXPECT_TRUE(adt.getPostion().x == 0);
    EXPECT_TRUE(adt.getPostion().y == 0);
    EXPECT_TRUE(adt.getPostion().z == 0);

    EXPECT_TRUE(adt.getScale().x == 0);
    EXPECT_TRUE(adt.getScale().y == 0);
    EXPECT_TRUE(adt.getScale().z == 0);

    EXPECT_TRUE(adt.getRotation().x == 0);
    EXPECT_TRUE(adt.getRotation().y == 0);
    EXPECT_TRUE(adt.getRotation().z == 0);

    adt.setPostion(Point3D{1,2,3});
    adt.setScale(Point3D{1,2,3});
    adt.setRotation(Point3D{1,2,3});

    EXPECT_TRUE(adt.getPostion().x == 1);
    EXPECT_TRUE(adt.getPostion().y == 2);
    EXPECT_TRUE(adt.getPostion().z == 3);

    EXPECT_TRUE(adt.getScale().x == 1);
    EXPECT_TRUE(adt.getScale().y == 2);
    EXPECT_TRUE(adt.getScale().z == 3);

    EXPECT_TRUE(adt.getRotation().x == 1);
    EXPECT_TRUE(adt.getRotation().y == 2);
    EXPECT_TRUE(adt.getRotation().z == 3);

}