#include <acercadewindow.h>
#include <QTextEdit>
#include <QLabel>
#include <QPixmap>
#include <QPicture>
#include <QBoxLayout>


AcercaDeWindow::AcercaDeWindow(QWidget *parent) :
    QDialog(parent)
{
    //Inicialización del widget y el layout que se usará
    AcercaDeWidget_ = new QWidget(this);
    AcercaDeLayout_ = new QBoxLayout(QBoxLayout::TopToBottom,AcercaDeWidget_);
    AcercaDeWidget_->setLayout(AcercaDeLayout_);

    //Declaración de los elementos a usar
    QWidget* titulo_ = new QLabel("Reproductor Multimedia Curso OSL.");
    QLabel* logotipo_ = new QLabel;
    logotipo_->setPixmap(QPixmap(":/icons/resources/Logo.jpg"));
    QWidget* logo_ = logotipo_;
    QString cadena;
    cadena.append("Aquí seguro que iría un montonazo\n");
    cadena.append("de información súper útil de cómo\n");
    cadena.append("contactar con el desarrollador o\n");
    cadena.append("algo así.");
    QWidget* contenido_ = new QLabel(cadena);

    this->setMinimumSize(268,315);
    this->setMaximumSize(268,315);

    //Insercción de los elementos en el layout
    AcercaDeLayout_->addWidget(titulo_);
    AcercaDeLayout_->addWidget(logo_);
    AcercaDeLayout_->addWidget(contenido_);
}

AcercaDeWindow::~AcercaDeWindow(){}

void AcercaDeWindow::LeerAcercaDe(){
   exec();
}
