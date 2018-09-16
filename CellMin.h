//
// Created by Jody Ciappelli on 14/09/18.
//

#ifndef SPREADSHEETJC_CELLMIN_H
#define SPREADSHEETJC_CELLMIN_H

#include "Cell.h"
#include "Observer.h"

class CellMin : public Cell, public Observer {
public:
    void update() override;
    void formula() override;
    void setData(int role, const QVariant &value) override;
};


#endif //SPREADSHEETJC_CELLMIN_H
