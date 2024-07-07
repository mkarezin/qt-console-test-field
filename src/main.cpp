#include <QCoreApplication>

#include "logger.h"
#include "test-qstring.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Logger logger("test.txt", "debug");
    logger.log("Hello, world!");

    TestQString test;

    qDebug() << test.toUpper("world");

    return 0;

    return a.exec();
}
