//
// Created by Jody Ciappelli on 14/09/18.
//

#ifndef SPREADSHEETJC_CELLAVG_H
#define SPREADSHEETJC_CELLAVG_H


#include "Cell.h"
#include "Observer.h"

class CellAvg : public Cell, public Observer {
public:
    void update() override;
    void formula() override;
    void setData(int role, const QVariant &value) override;
    virtual ~CellAvg(){}
};


#endif //SPREADSHEETJC_CELLAVG_H
