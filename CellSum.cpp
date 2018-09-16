//
// Created by Jody Ciappelli on 14/09/18.
//

#include <iostream>
#include "CellSum.h"

void CellSum::update() {
    this->formula();
}

void CellSum::formula() {
    double sum = 0;
    for(int i = 1; i <= RowCount - 1; i++){
        sum += tableWidget()->item(i, 0)->text().toInt();
    }
    this->tableWidget()->item(1, 5)->setText(QString::number(sum));
}

void CellSum::setData(int role, const QVariant &value) {
    QTableWidgetItem::setData(role, value);
    if (role == Qt::EditRole) {
        setDirty();
        this->formula();
    }
}
