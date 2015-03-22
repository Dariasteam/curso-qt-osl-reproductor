#ifndef ACERCADEWINDOW_H
#define ACERCADEWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDir>
#include <QSlider>
#include <QFileDialog>
#include <QToolButton>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDialog>
#include <QMessageBox>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>
#include <QDebug>
#include <QBoxLayout>

class AcercaDeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AcercaDeWindow(QWidget *parent = 0);
    ~AcercaDeWindow();

private:
    QWidget*            AcercaDeWidget_; //Wideget del dialog
    QBoxLayout*        AcercaDeLayout_;

private slots:
    void LeerAcercaDe();
};

#endif // ACERCADEWINDOW_H
