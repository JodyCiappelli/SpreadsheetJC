//
// Created by Jody Ciappelli on 14/09/18.
//

#include <iostream>
#include "CellAvg.h"

void CellAvg::update() {
    this->formula();
}

void CellAvg::formula() {
    double sum = 0;
    for(int i = 1; i <= RowCount - 1;i++){
        sum += tableWidget()->item(i, 0)->text().toInt();
    }
    this->tableWidget()->item(1, 4)->setText(QString::number(sum / (RowCount - 1)));
}

void CellAvg::setData(int role, const QVariant &value) {
    QTableWidgetItem::setData(role, value);
    if (role == Qt::EditRole) {
        setDirty();
        this->formula();
    }
}
