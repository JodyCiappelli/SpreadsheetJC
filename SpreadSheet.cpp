//
// Created by Jody Ciappelli on 05/09/18.
//
#include <QtGui>
#include "Cell.h"
#include "SpreadSheet.h"
#include "CellVal.h"
#include "CellMin.h"
#include "CellMax.h"
#include "CellAvg.h"
#include "CellSum.h"
#include <QTableWidget>
#include <iostream>

SpreadSheet::SpreadSheet() {
    setItemPrototype(new CellVal);
    setSelectionMode(ContiguousSelection);
    create();
}

SpreadSheet::SpreadSheet(bool test) {
    setItemPrototype(new CellVal);
    setSelectionMode(ContiguousSelection);
    setRowCount(0);
    setColumnCount(0);

    setRowCount(RowCount);
    setColumnCount(ColumnCount);

    for (int i = 0; i < ColumnCount; ++i) {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString(QChar('A' + i)));
        setHorizontalHeaderItem(i, item);
    }

    setCurrentCell(0, 0);

    CellMin *cellMin = new CellMin;
    setItem(1, 2, cellMin);
    CellMax *cellMax = new CellMax;
    setItem(1, 3, cellMax);
    CellAvg *cellAvg = new CellAvg;
    setItem(1, 4, cellAvg);
    CellSum *cellSum = new CellSum;
    setItem(1, 5, cellSum);

    for (int i = 1; i <= RowCount - 1; i++) {
        CellVal *cell = new CellVal;
        cell->setText(QString::number(i));
        setItem(i, 0, cell);
    }

    cellMin->formula();

    cellMax->formula();

    cellAvg->formula();

    cellSum->formula();

}

SpreadSheet::SpreadSheet(QWidget *parent): QTableWidget(parent) {
    setItemPrototype(new CellVal);
    setSelectionMode(ContiguousSelection);
    create();
}

void SpreadSheet::create() {
    setRowCount(0);
    setColumnCount(0);
    setRowCount(RowCount);
    setColumnCount(ColumnCount);

    for (int i = 0; i < ColumnCount; ++i) {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString(QChar('A' + i)));
        setHorizontalHeaderItem(i, item);
    }
    setCurrentCell(0, 0);

    QTableWidgetItem *itemVal = new QTableWidgetItem;
    itemVal->setText(QString("Values"));
    itemVal->setBackgroundColor(Qt::red);
    setItem(0, 0, itemVal);

    QTableWidgetItem *itemMin = new QTableWidgetItem;
    itemMin->setText(QString("Minimum"));
    itemMin->setBackgroundColor(Qt::darkCyan);
    setItem(0, 2, itemMin);

    QTableWidgetItem *itemMax = new QTableWidgetItem;
    itemMax->setText(QString("Maximum"));
    itemMax->setBackgroundColor(Qt::darkCyan);
    setItem(0, 3, itemMax);

    QTableWidgetItem *itemAvg = new QTableWidgetItem;
    itemAvg->setText(QString("Average"));
    itemAvg->setBackgroundColor(Qt::darkCyan);
    setItem(0, 4, itemAvg);

    QTableWidgetItem *itemSum = new QTableWidgetItem;
    itemSum->setText(QString("Sum"));
    itemSum->setBackgroundColor(Qt::darkCyan);
    setItem(0, 5, itemSum);

    CellMin *cellMin = new CellMin;
    setItem(1, 2, cellMin);
    CellMax *cellMax = new CellMax;
    setItem(1, 3, cellMax);
    CellAvg *cellAvg = new CellAvg;
    setItem(1, 4, cellAvg);
    CellSum *cellSum = new CellSum;
    setItem(1, 5, cellSum);

    for(int i = 1; i <= RowCount - 1; i++) {
        CellVal *cellVal = new CellVal;
        std::cout << "Inserisci i valori : " << std::endl;
        int j = 0;
        std::cin >> j;
        cellVal->setText(QString::number(j));
        setItem(i , 0, cellVal);

        cellVal->attach(cellMin);
        cellVal->attach(cellMax);
        cellVal->attach(cellAvg);
        cellVal->attach(cellSum);
    }
    std::cout << "Inserimento dei valori completato " << std::endl;

    cellMin->formula();

    cellMax->formula();

    cellAvg->formula();

    cellSum->formula();

    for (int i = 3; i <= RowCount - 1; i++) {
        for (int j = 2; j <= ColumnCount - 1; j++){
            Cell *item123 = new CellVal;
            setItem(i, j, item123);
        }
    }
}

Cell *SpreadSheet::cell(int row, int column) const {
    return static_cast<Cell *>(item(row, column));
}


QTableWidgetItem* SpreadSheet::itemXY(int r, int c) {
    return item(r,c);
}

