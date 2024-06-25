#include <QCoreApplication>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QSerialPortInfo> portInfoList = QSerialPortInfo::availablePorts();

    for (QSerialPortInfo &portInfo: portInfoList)
    {
        qDebug() << "portName: " << portInfo.portName() << "\n"
                 << "systemLocation: " << portInfo.systemLocation() << "\n"
                 << "description: " << portInfo.description() << "\n"
                 << "manufacturer: " << portInfo.manufacturer() << "\n"
                 << "serialNumber: " << portInfo.serialNumber() << "\n"
                 << "vendorIdentifier: "
                 << (portInfo.hasVendorIdentifier()
                     ? QByteArray::number(portInfo.vendorIdentifier(), 16)
                     : QByteArray()) << "\n"
                 << "productIdentifier: "
                 << (portInfo.hasProductIdentifier()
                     ? QByteArray::number(portInfo.productIdentifier(), 16)
                     : QByteArray()) << "\n";
    }

    return 0;
}
