//
// Created by Jody Ciappelli on 14/09/18.
//

#ifndef SPREADSHEETJC_ABSTRACTSUBJECT_H
#define SPREADSHEETJC_ABSTRACTSUBJECT_H

#include "Observer.h"
#include <list>

class Subject {

public:
    void attach(Observer *abstractObserver);
    void detach(Observer *abstractObserver);
    void notify();

protected:
    std::list<Observer*> observers;
};


#endif //SPREADSHEETJC_ABSTRACTSUBJECT_H
