#include "test-gui.h"

#include <QTest>
#include <QLineEdit>
#include <QString>

TestGui::TestGui(QObject *parent)
    : QObject{parent}
{}

void TestGui::testGui()
{
    QFETCH(QTestEventList, events);
    QFETCH(QString, expected);

    QLineEdit lineEdit;

    events.simulate(&lineEdit);

    QCOMPARE(lineEdit.text(), expected);
}

void TestGui::testGui_data()
{
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<QString>("expected");

    QTestEventList eventList;
    eventList.addKeyClick('a');
    QTest::newRow("char") << eventList << "a";

    QTestEventList eventList2;
    eventList2.addKeyClick('a');
    eventList2.addKeyClick(Qt::Key_Backspace);
    QTest::newRow("there+back_again") << eventList2 << "";
}
