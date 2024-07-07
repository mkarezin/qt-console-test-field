#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QFile>

class Logger
{
private:
    QString *name;
    QFile *file;

public:
    Logger(QString const &filePath, QString const &name);
    ~Logger();
    void log(QString const &message) const;
};

#endif // LOGGER_H
