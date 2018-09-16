//
// Created by Jody Ciappelli on 14/09/18.
//

#include <iostream>
#include <QtCore/QCoreApplication>
#include "CellVal.h"
#include "CellMin.h"
#include "CellMax.h"
#include "CellSum.h"
#include "CellAvg.h"

int CellVal::getValue() const {
    return value;
}
void CellVal::setValue(int value) {
    CellVal::value = value;
}
void CellVal::formula() {}

void CellVal::setData(int role, const QVariant &value) {
    QTableWidgetItem::setData(role, value);
    if (role == Qt::EditRole) {
        setDirty();
        notify();
    }
}

CellVal::~CellVal() {
    for(auto itr = std::begin(observers); itr != std::end(observers); itr++) {
        this->detach((*itr));
    }
}