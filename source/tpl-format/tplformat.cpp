#include "tplformat.h"
#include "tplfile.h"

tplFormat::tplFormat(QObject *parent) : QObject(parent)
{
    formatArgs = nullptr;
}

tplFormat::tplFormat(arguments *args, QObject *parent) : QObject(parent)
{
    formatArgs = args;
}

void tplFormat::format()
{
    tplFile file;
    // check for file name
    if (!formatArgs->getTplFile().isEmpty())
    {
        file.setFileName(formatArgs->getTplFile());

        // process file
        file.setFileName(formatArgs->getTplFile());
        file.process(*formatArgs);
    }
    else
    {
        qWarning("No file provided.");
        formatArgs->showUsage();
    }

    emit done(true);
}
