#include "tplfile.h"

#include <QStringList>

tplFile::tplFile() : QFile()
{
    localCalcsSection = false;
}
tplFile::tplFile(QString &newName) : QFile(newName)
{
    localCalcsSection = false;
}

// read file, make changes, and write out
void tplFile::process(arguments &args)
{
    QString textin;
    QStringList lines;
    QString line;
    QString textout;

    if (exists())
    {
    if (open(QIODevice::ReadOnly))
    {
        if (isReadable())
        {
            textin = QString(readAll());
        }
        else
        {
            qFatal("Tpl file is unreadable.");
        }
        close();
    }
    else
    {
        qFatal("Could not open Tpl file for reading.");
    }
    if (!textin.isEmpty())
    {
        if (open(QIODevice::WriteOnly))
        {
            lines = textin.split('\n');
            for (int i = 0; i < lines.count(); i++)
            {
                line = lines.at(i);
                line = processLine(line);
                line.append('\n');
                write(line.toUtf8());
            }
            close();
        }
        else
        {
            qFatal("Could not open Tpl file for writing.");
        }
    }
    }
    else
    {
        qFatal("File does not exist.");
    }

}

QString &tplFile::processLine(QString &txt)
{
    QStringList tokens = txt.split(' ', QString::SkipEmptyParts);
    if (tokens.count() > 0)
    {
        QString first = tokens.at(0);
        if (localCalcsSection)
        {
            txt.prepend("  ");
        }
        else if    (first.startsWith("init")
                 || first.startsWith("!!"))
        {
            txt = txt.trimmed();
        }

        if        (first.startsWith("FUNCTION")
                || first.startsWith("SEPARABLE_FUNCTION")
                || first.startsWith("DATA_SECTION")
                || first.startsWith("INITIALIZATION_SECTION")
                || first.startsWith("PARAMETER_SECTION")
                || first.startsWith("PELIMINARY_CALCS_SECTION")
                || first.startsWith("PROCEDURE_SECTION")
                || first.startsWith("REPORT_SECTION")
                || first.startsWith("RUNTIME_SECTION")
                || first.startsWith("TOP_OF_MAIN_SECTION")
                || first.startsWith("GLOBALS_SECTION")
                || first.startsWith("BETWEEN_PHASES_SECTION")
                || first.startsWith("NORMAL_PRIOR_SECTION")
                || first.startsWith("FINAL_SECTION"))
        {}
        else if   (first.startsWith("LOCAL_CALCS")
                || first.startsWith("LOC_CALCS")
                || first.startsWith("END_CALCS")
                || first.startsWith("USER_CODE"))
        {
            if      (first.startsWith("LOCAL_CALCS")
                  || first.startsWith("LOC_CALCS"))
                localCalcsSection = true;
            else if (first.startsWith("END_CALCS"))
                localCalcsSection = false;
            txt = QString(" ") + first;
        }
        else if   (txt.startsWith("/*"))
        {
            txt.prepend(" ");
        }
        else if   (first.startsWith("//")
                || txt.startsWith("  ")
                || first.startsWith("!!"))
        {}
        else
        {
            txt.prepend("  ");
        }
    }
    return txt;
}
