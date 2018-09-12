#include <iostream>
#include "Cell.h"
#include "SpreadSheet.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QtGui>
#include <QApplication>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

void runTests(int argc, char* argv[]);

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QTableWidget *parent;
    runTests(argc, argv);
    SpreadSheet spreadSheet(parent);
    spreadSheet.show();
    app.exec();
}

void runTests(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    int i = RUN_ALL_TESTS();
    if (i != 0){
        std::cout << "Something wrong " << std::endl;
    }
}