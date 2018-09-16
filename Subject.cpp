//
// Created by Jody Ciappelli on 14/09/18.
//
#include <iostream>
#include "Subject.h"
#include "Cell.h"

void Subject::notify() {
    for(auto itr = std::begin(observers); itr != std::end(observers); itr++) {
        (*itr)->update();
    }
}

void Subject::attach(Observer *abstractObserver) {
    observers.push_back(abstractObserver);
}

void Subject::detach(Observer *abstractObserver) {
    observers.remove(abstractObserver);
}
