#include <recienteaction.h>
#include <QFileDialog>
#include <QWidget>
#include <QMediaContent>

RecienteAction::RecienteAction(QWidget* parent, QMediaPlayer* player, QString string) :
    QAction(parent)
{
    mediaPlayer_=player;
    archivo_=string;
    archivo_.chop(1);   //Elimina el char de salto de linea
}

RecienteAction::~RecienteAction(){}

void RecienteAction::Pulsar(){
    //Utilizo un constructor de QUrl mágico
    if (archivo_ != "") {
        mediaPlayer_->setMedia(QUrl(archivo_));
        mediaPlayer_->play();
    }
}
