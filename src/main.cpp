#include <QCoreApplication>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>

static bool isUSBToSerialConverter(QSerialPortInfo &portInfo);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QSerialPortInfo> portInfoList = QSerialPortInfo::availablePorts();

    for (QSerialPortInfo &portInfo: portInfoList)
    {
        if (!isUSBToSerialConverter(portInfo))
            continue;

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

static bool isUSBToSerialConverter(QSerialPortInfo &portInfo)
{
    QString portDescription = portInfo.description();

    return ((portDescription.contains("usb", Qt::CaseInsensitive)) ||
            (portDescription.contains("serial", Qt::CaseInsensitive)) ||
            (portDescription.contains("CH34", Qt::CaseInsensitive)));
}
