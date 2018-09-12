//
// Created by Jody Ciappelli on 10/09/18.
//

#include <gtest/gtest.h>
#include "SpreadSheet.h"

TEST(SpreadSheet, correctMin) {
    SpreadSheet spreadSheet(true);
    ASSERT_EQ(1, spreadSheet.itemXY(1,2)->text().toInt());
}

TEST(SpreadSheet, correctMax) {
    SpreadSheet spreadSheet(true);
    ASSERT_EQ(15, spreadSheet.itemXY(1,3)->text().toInt());
}

TEST(SpreadSheet, correctAvg) {
    SpreadSheet spreadSheet(true);
    ASSERT_EQ(8, spreadSheet.itemXY(1,4)->text().toInt());
}

TEST(SpreadSheet, correctSum) {
    SpreadSheet spreadSheet(true);
    ASSERT_EQ(120, spreadSheet.itemXY(1,5)->text().toInt());
}