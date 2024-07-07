#ifndef TESTGUI_H
#define TESTGUI_H

#include <QObject>
#include <QtWidgets>

class TestGui : public QObject
{
    Q_OBJECT
public:
    explicit TestGui(QObject *parent = nullptr);

private slots:
    void testGui();
    void testGui_data();

signals:
};

#endif // TESTGUI_H
