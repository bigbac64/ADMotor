//
// Created by Antoine DESOBRY on 25/08/2022.
//

#include <gtest/gtest.h>

TEST(RandomTest, divide_int){
    EXPECT_TRUE(1000/60 == 16);
    EXPECT_TRUE(1000/30 == 33);
}