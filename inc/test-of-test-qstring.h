#ifndef TESTOFTESTQSTRING_H
#define TESTOFTESTQSTRING_H

#include <QObject>

#include "test-qstring.h"

class TestOfTestQString : public QObject
{
    Q_OBJECT
public:
    explicit TestOfTestQString(QObject *parent = nullptr);

private:
    TestQString test;

private slots:
    void toUpper();
    void toUpper_data();

signals:
};

#endif // TESTOFTESTQSTRING_H
