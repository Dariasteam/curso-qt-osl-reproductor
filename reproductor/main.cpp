#include <acercadewindow.h>
#include <mainwindow.h>
#include <imagenwindow.h>


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.LeerRecientes();
    w.show();
    
    return a.exec();
}
