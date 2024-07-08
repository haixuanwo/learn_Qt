#ifndef EXCELENGINE_H
#define EXCELENGINE_H

#include <QObject>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <QAxBase>
#include <QAxObject>
#include <QTableWidget>
#include <QTableView>
#include <QTableWidgetItem>
#include <QDebug>

class ExcelEngine : public QObject
{
    Q_OBJECT
public:
    explicit ExcelEngine(QObject *parent = nullptr);

signals:

};

#endif // EXCELENGINE_H
