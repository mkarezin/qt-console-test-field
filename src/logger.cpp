#include "logger.h"

#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDateTime>

Logger::Logger(QString const &filePath, QString const &name)
{
    this->name = new QString(name);
    this->file = new QFile(filePath);
}

Logger::~Logger()
{
    delete name;
    delete file;
}

void Logger::log(QString const &message) const
{
    if (file->open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
    {
        QTextStream textStream(file);
        QDateTime timestamp(QDate::currentDate(), QTime::currentTime());

        textStream << timestamp.toString("yyyy-MM-dd hh:mm:ss.zzz") << " | <" << *name << "> ";

        textStream << message << Qt::endl;
        file->close();
    }
}
