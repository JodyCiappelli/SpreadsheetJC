//
// Created by Jody Ciappelli on 05/09/18.
//
#include <QtGui>
#include "Cell.h"
#include "SpreadSheet.h"
#include <QTableWidget>
#include <iostream>

SpreadSheet::SpreadSheet() {
    setItemPrototype(new Cell);
    setSelectionMode(ContiguousSelection);
    clear();
}

SpreadSheet::SpreadSheet(bool test) {
    setItemPrototype(new Cell);
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

    Cell *cellMin = new Cell;
    setItem(1, 2, cellMin);
    Cell *cellMax = new Cell;
    setItem(1, 3, cellMax);
    Cell *cellAvg = new Cell;
    setItem(1, 4, cellAvg);
    Cell *cellSum = new Cell;
    setItem(1, 5, cellSum);

    Cell *cell1 = new Cell;
    Cell *cell2 = new Cell;
    Cell *cell3 = new Cell;
    Cell *cell4 = new Cell;
    Cell *cell5 = new Cell;
    Cell *cell6 = new Cell;
    Cell *cell7 = new Cell;
    Cell *cell8 = new Cell;
    Cell *cell9 = new Cell;
    Cell *cell10 = new Cell;
    Cell *cell11 = new Cell;
    Cell *cell12 = new Cell;
    Cell *cell13 = new Cell;
    Cell *cell14 = new Cell;
    Cell *cell15 = new Cell;

    cell1->setText(QString::number(1));
    setItem(1, 0, cell1);
    cell2->setText(QString::number(2));
    setItem(2, 0, cell2);
    cell3->setText(QString::number(3));
    setItem(3, 0, cell3);
    cell4->setText(QString::number(4));
    setItem(4, 0, cell4);
    cell5->setText(QString::number(5));
    setItem(5, 0, cell5);
    cell6->setText(QString::number(6));
    setItem(6, 0, cell6);
    cell7->setText(QString::number(7));
    setItem(7, 0, cell7);
    cell8->setText(QString::number(8));
    setItem(8, 0, cell8);
    cell9->setText(QString::number(9));
    setItem(9, 0, cell9);
    cell10->setText(QString::number(10));
    setItem(10, 0, cell10);
    cell11->setText(QString::number(11));
    setItem(11, 0, cell11);
    cell12->setText(QString::number(12));
    setItem(12, 0, cell12);
    cell13->setText(QString::number(13));
    setItem(13, 0, cell13);
    cell14->setText(QString::number(14));
    setItem(14, 0, cell14);
    cell15->setText(QString::number(15));
    setItem(15, 0, cell15);

    cellAvg->minCell();

    cellAvg->maxCell();

    cellAvg->averageCell();

    cellSum->sumCell();

}

SpreadSheet::SpreadSheet(QWidget *parent): QTableWidget(parent) {
    setItemPrototype(new Cell);
    setSelectionMode(ContiguousSelection);
    clear();
}

void SpreadSheet::clear() {
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

    Cell *cellMin = new Cell;
    setItem(1, 2, cellMin);
    Cell *cellMax = new Cell;
    setItem(1, 3, cellMax);
    Cell *cellAvg = new Cell;
    setItem(1, 4, cellAvg);
    Cell *cellSum = new Cell;
    setItem(1, 5, cellSum);

    for(int i = 1; i <= RowCount - 1; i++){
        Cell *cellVal = new Cell;
        std::cout << "Inserisci i valori : " << std::endl;
        int j = 0;
        std::cin >> j;
        cellVal->setText(QString::number(j));
        setItem(i, 0, cellVal);
    }

    cellAvg->minCell();

    cellAvg->maxCell();

    cellAvg->averageCell();

    cellSum->sumCell();

    for (int i = 3; i <= RowCount - 1; i++){
        for (int j = 2; j <= ColumnCount - 1; j++){
            Cell *item123 = new Cell;
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



