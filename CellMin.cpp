//
// Created by Jody Ciappelli on 14/09/18.
//

#include <iostream>
#include "CellMin.h"

void CellMin::update() {
    this->formula();
}

void CellMin::formula() {
    int min = 9999;
    for(int i = 1; i <= RowCount - 1; i++){
        if(tableWidget()->item(i, 0)->text().toInt() < min)
            min = tableWidget()->item(i, 0)->text().toInt();
    }
    this->tableWidget()->item(1, 2)->setText(QString::number(min));
}

void CellMin::setData(int role, const QVariant &value) {
    QTableWidgetItem::setData(role, value);
    if (role == Qt::EditRole) {
        setDirty();
        this->formula();
    }
}
