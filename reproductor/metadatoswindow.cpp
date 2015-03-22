#include <metadatoswindow.h>
#include <QTextEdit>
#include <QLabel>
#include <QPixmap>
#include <QPicture>
#include <QBoxLayout>
#include <QMediaMetaData>


MetadatosWindow::MetadatosWindow(QMediaPlayer* M, QWidget *parent) :
    QDialog(parent)
{
    mediaPlayer_=M;
}

MetadatosWindow::~MetadatosWindow(){}

void MetadatosWindow::MostrarMetadatos(){
   A = new QWidget*[8];
   MetadatosWidget_ = new QWidget(this);
   MetadatosLayout_ = new QBoxLayout(QBoxLayout::TopToBottom,MetadatosWidget_);
   MetadatosWidget_->setLayout(MetadatosLayout_);
   QWidget* cabecera_ = new QLabel("Metadatos:");
   MetadatosLayout_->addWidget(cabecera_);
   if(mediaPlayer_->isMetaDataAvailable()){
        A[0] = new QLabel("Título:");
        A[1] = new QLabel(mediaPlayer_->metaData(QMediaMetaData::Title).toString());
        A[2] = new QLabel("Autor:");
        A[3] = new QLabel((mediaPlayer_->metaData(QMediaMetaData::Author)).toString());
        A[4] = new QLabel("Duración:");
        A[5] = new QLabel((mediaPlayer_->metaData(QMediaMetaData::Duration)).toString());
        A[6] = new QLabel("Año:");
        A[7] = new QLabel((mediaPlayer_->metaData(QMediaMetaData::Year)).toString());
        int sz_=0;
        for(int i=0;i<8;i++){
            MetadatosLayout_->addWidget(A[i]);
            if(A[i]->frameSize().width()>sz_){
                sz_=A[i]->width();
            }
        }
        this->setMinimumSize(sz_,315);
   }else{
        QWidget* nohay_ = new QLabel("Este archivo no tiene metadatos");
        MetadatosLayout_->addWidget(nohay_);
   }
   exec();

}

