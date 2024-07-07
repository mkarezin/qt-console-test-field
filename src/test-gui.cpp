#include "test-gui.h"

#include <QTest>
#include <QLineEdit>
#include <QString>

TestGui::TestGui(QObject *parent)
    : QObject{parent}
{}

void TestGui::testGui()
{
    QLineEdit lineEdit;

    QTest::keyClicks(&lineEdit, "hello world");

    QCOMPARE(lineEdit.text(), QString("hello world"));
}
