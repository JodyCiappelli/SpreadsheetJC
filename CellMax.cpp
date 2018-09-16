//
// Created by Jody Ciappelli on 14/09/18.
//

#include <iostream>
#include "CellMax.h"

void CellMax::update() {
    this->formula();
}

void CellMax::formula() {
    int max = -9999;
    for(int i = 1; i <= RowCount - 1; i++){
        if(tableWidget()->item(i, 0)->text().toInt() > max)
            max = tableWidget()->item(i, 0)->text().toInt();
    }
    this->tableWidget()->item(1, 3)->setText(QString::number(max));
}

void CellMax::setData(int role, const QVariant &value) {
    QTableWidgetItem::setData(role, value);
    if (role == Qt::EditRole) {
        setDirty();
        this->formula();
    }
}
