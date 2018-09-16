//
// Created by Jody Ciappelli on 14/09/18.
//

#ifndef SPREADSHEETJC_CELLVAL_H
#define SPREADSHEETJC_CELLVAL_H

#include "Cell.h"
#include "Subject.h"

class CellVal : public Cell, public Subject {

public:
    int getValue() const;
    void setValue(int value);
    void formula() override;

    void setData(int role, const QVariant &value) override;

private:
    int value;
};


#endif //SPREADSHEETJC_CELLVAL_H
