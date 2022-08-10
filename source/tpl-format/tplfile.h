#ifndef TPLFILE_H
#define TPLFILE_H

#include "arguments.h"

#include <QFile>
#include <QObject>

class tplFile : public QFile
{
public:
    tplFile();
    tplFile(QString &newName);

    void process(arguments &args);
    QString &processLine(QString &txt);

    QString &determineLineEnding(QString line);

private:
    QString lineEnd;
    bool localCalcsSection;
};

#endif // TPLFILE_H
