//
// Created by Jody Ciappelli on 05/09/18.
//

#ifndef SPREADSHEETJC_CELL_H
#define SPREADSHEETJC_CELL_H


#include <QtWidgets/QTableWidgetItem>


class Cell : public QTableWidgetItem{
public:
    Cell();
    virtual void setData(int role, const QVariant &value) = 0;
    QVariant data(int role) const;
    void setFormula(const QString &formula);
    QString formula() const;
    void setDirty();
    virtual void formula() = 0;
protected:
    enum { RowCount = 16 };
private:
    QVariant value() const;
    QVariant evalExpression(const QString &str, int &pos) const;
    QVariant evalTerm(const QString &str, int &pos) const;
    QVariant evalFactor(const QString &str, int &pos) const;
    mutable QVariant cachedValue;
    mutable bool cacheIsDirty;
};

#endif //SPREADSHEETJC_CELL_H