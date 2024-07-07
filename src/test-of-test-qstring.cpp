#include "test-of-test-qstring.h"

#include <QTest>
#include <QString>

TestOfTestQString::TestOfTestQString(QObject *parent)
    : QObject{parent}
{}

void TestOfTestQString::toUpper()
{
    QString str = "hello";
    QVERIFY(test.toUpper(str) == "HELLO");
    QCOMPARE(test.toUpper(str), QString("HELLO"));
}
