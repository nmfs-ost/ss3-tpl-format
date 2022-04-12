#include <QCoreApplication>

#include "arguments.h"
#include "tplfile.h"
#include "tplformat.h"

// repair damage from clang-format
// adds back 2 spaces at beginning of lines


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // read arguments
    arguments *args = new arguments(qApp->arguments());

    tplFormat tpl(args);
    QObject::connect(&tpl, SIGNAL(done(bool)),
                     &a, SLOT(quit()), Qt::QueuedConnection);
    tpl.format();

    return a.exec();
}
