#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <QStringList>

class arguments
{
public:
    arguments(QStringList args);

    void showUsage();

    const QString &getTplFile() const;
    void setTplFile(const QString &newTplFile);

    const QString &getOptionsFile() const;
    void setOptionsFile(const QString &newOptionsFile);

    int getTabSpaces() const;
    void setTabSpaces(int newTabSpaces);

private:
    QString tplFile;
    QString optionsFile;
    int tabSpaces;
};

#endif // ARGUMENTS_H
