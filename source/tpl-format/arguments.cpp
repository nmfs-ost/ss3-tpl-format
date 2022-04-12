#include "arguments.h"

arguments::arguments(QStringList args)
{
    QString arg;
    setTplFile(QString());
    setOptionsFile(QString());
    setTabSpaces(2);

    for (int i = 1; i < args.count(); i++)
    {
        arg = args.at(i);
        if (arg.startsWith("-"))
        {
            continue; // ignore for now
        }
        else
        {
            setTplFile(arg);
        }
    }
}

void arguments::showUsage()
{
    QString usage;

}

const QString &arguments::getTplFile() const
{
    return tplFile;
}

void arguments::setTplFile(const QString &newTplFile)
{
    tplFile = newTplFile;
}

const QString &arguments::getOptionsFile() const
{
    return optionsFile;
}

void arguments::setOptionsFile(const QString &newOptionsFile)
{
    optionsFile = newOptionsFile;
}

int arguments::getTabSpaces() const
{
    return tabSpaces;
}

void arguments::setTabSpaces(int newTabSpaces)
{
    tabSpaces = newTabSpaces;
}
