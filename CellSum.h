//
// Created by Jody Ciappelli on 14/09/18.
//

#ifndef SPREADSHEETJC_CELLSUM_H
#define SPREADSHEETJC_CELLSUM_H

#include "Cell.h"
#include "Observer.h"

class CellSum : public Cell, public Observer {
public:
    void update() override;
    void formula() override;
    void setData(int role, const QVariant &value) override;
    virtual ~CellSum(){}
};


#endif //SPREADSHEETJC_CELLSUM_H
