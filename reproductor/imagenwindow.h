#ifndef IMAGENWINDOW_H
#define IMAGENWINDOW_H

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

class ImagenWIndow : public QDialog
{
    Q_OBJECT

public:
    explicit ImagenWIndow(QWidget*, QVideoWidget*);
    ~ImagenWIndow();

private:
    QWidget*            ImagenWidget_; //Wideget del dialog
    QGridLayout*        ImagenLayout_;
    QVideoWidget*       Pantalla_;

private slots:
    void Controles();
};

#endif // ImagenWIndow_H
