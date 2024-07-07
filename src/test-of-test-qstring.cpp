#include "test-of-test-qstring.h"

#include <QTest>
#include <QString>

TestOfTestQString::TestOfTestQString(QObject *parent)
    : QObject{parent}
{}

void TestOfTestQString::toUpper()
{
    QFETCH(QString, string);
    QFETCH(QString, result);

    QCOMPARE(test.toUpper(string), result);
}

void TestOfTestQString::toUpper_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    QTest::newRow("all-lower") << "hello" << "HELLO";
    QTest::newRow("mixed") << "Hello" << "HELLO";
    QTest::newRow("all-upper") << "HELLO" << "HELLO";
}
