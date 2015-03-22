#ifndef METADATOSWINDOW_H
#define METADATOSWINDOW_H

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
#include <QDebug>
#include <QBoxLayout>

class MetadatosWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MetadatosWindow(QMediaPlayer*, QWidget *parent = 0);
    ~MetadatosWindow();

private:
    QWidget*           MetadatosWidget_; //Wideget del dialog
    QBoxLayout*        MetadatosLayout_;
    QMediaPlayer*      mediaPlayer_;
    QWidget**          A;

private slots:
    void MostrarMetadatos();
};

#endif // METADATOSWINDOW_H
