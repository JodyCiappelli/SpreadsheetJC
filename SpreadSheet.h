//
// Created by Jody Ciappelli on 05/09/18.
//

#ifndef SPREADSHEETJC_SPREADSHEET_H
#define SPREADSHEETJC_SPREADSHEET_H

#include <QTableWidget>
#include <iostream>
#include "Cell.h"


class SpreadSheet : public QTableWidget{
public:
    explicit SpreadSheet(QWidget *parent = nullptr);
    SpreadSheet();
    explicit SpreadSheet(bool test);
    void clear();
    QTableWidgetItem* itemXY(int r, int c);


private:
    enum { RowCount = 16, ColumnCount = 26 };
    Cell *cell(int row, int column) const;
};


#endif //SPREADSHEETJC_SPREADSHEET_H
