//
// Created by Jody Ciappelli on 14/09/18.
//

#ifndef SPREADSHEETJC_CELLMAX_H
#define SPREADSHEETJC_CELLMAX_H

#include "Cell.h"
#include "Observer.h"

class CellMax : public Cell, public Observer {

public:
    void update() override;
    void formula() override;
    void setData(int role, const QVariant &value) override;
    virtual ~CellMax(){}
};


#endif //SPREADSHEETJC_CELLMAX_H
