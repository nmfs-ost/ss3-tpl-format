#ifndef TPLFORMAT_H
#define TPLFORMAT_H

#include "arguments.h"

#include <QObject>

class tplFormat : public QObject
{
    Q_OBJECT
public:
    explicit tplFormat(QObject *parent = nullptr);
    tplFormat(arguments *args, QObject *parent = nullptr);

    void format();
signals:
    void done(bool);

private:
    arguments *formatArgs;
};

#endif // TPLFORMAT_H
