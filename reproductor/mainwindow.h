#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include <QKeySequence>
#include <QMediaMetaData>
#include <acercadewindow.h>
#include <imagenwindow.h>
#include <recienteaction.h>
#include <metadatoswindow.h>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void LeerRecientes();
    void GuardarRecientes(QString);

private:
    QGridLayout*        lytMain_;
    QWidget*            wgtMain_;
    QMediaPlayer*       mediaPlayer_;
    QSlider*            playerSlider_;
    QVideoWidget*       videoWidget_;
    QSlider*            volumeSlider_;
    QToolButton*        btnOpen_;
    QToolButton*        btnPlay_;
    QToolButton*        btnPause_;
    QToolButton*        btnStop_;
    QMenuBar*           mainMenu_;
    QMenu*              Archivo_;
    QMenu*              Ayuda_;
    QMenu*              Ver_;
    QAction*            Abrir_;
    QAction*            AcercaDe_;
    QAction*            FullScreen_;
    QMenu*              Recientes_;
    RecienteAction**    Reciente_v;
    QAction**           Reciente_s;
    QAction*            Metadatos_;
    AcercaDeWindow*     Ventana_;
    QMenu*              Editar_;
    QAction*            Imagen_;
    ImagenWIndow*       Controles_;
    MetadatosWindow*    MetadatosW_;
    bool                playing_;



private slots:
    void onOpen();
    void onSeek();
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);
    void onVolumeChanged(int volume);
    void Max_Min();
    void onOpenRecent(QString fileName);

public slots:
    void playPause();
};

#endif // MAINWINDOW_H
