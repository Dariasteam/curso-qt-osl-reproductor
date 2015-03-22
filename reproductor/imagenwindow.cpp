#include <imagenwindow.h>
#include <QTextEdit>
#include <QLabel>
#include <QPixmap>
#include <QPicture>


ImagenWIndow::ImagenWIndow(QWidget *parent,QVideoWidget* Video) :
    QDialog(parent)
{
    //Inicialización del widget y el layout que se usará
    ImagenWidget_ = new QWidget(this);
    ImagenLayout_ = new QGridLayout(ImagenWidget_);
    ImagenWidget_->setLayout(ImagenLayout_);
    Pantalla_ = Video;
    //Declaración de los elementos a usar
    QWidget* titulo_ = new QLabel("Controles de Imagen");

    QSlider* brillo_ = new QSlider(Qt::Vertical, this);
    QSlider* contraste_ = new QSlider(Qt::Vertical, this);
    QSlider* saturacion_ = new QSlider(Qt::Vertical, this);
    QWidget* Brillo_ = brillo_;
    QWidget* Contraste_ = contraste_;
    QWidget* Saturacion_ = saturacion_;

    brillo_->setRange(-100, 100);
    brillo_->setSliderPosition(0);
    contraste_->setRange(-100, 100);
    contraste_->setSliderPosition(0);
    saturacion_->setRange(-100, 100);
    saturacion_->setSliderPosition(0);

    QWidget* nombre1_ = new QLabel("Brillo");
    QWidget* nombre2_ = new QLabel("Contraste");
    QWidget* nombre3_ = new QLabel("Saturación");

    this->setMinimumSize(268,315);

    connect(brillo_, SIGNAL(sliderMoved(int)),Pantalla_,SLOT(setBrightness(int)));
    connect(contraste_, SIGNAL(sliderMoved(int)),Pantalla_,SLOT(setContrast(int)));
    connect(saturacion_, SIGNAL(sliderMoved(int)),Pantalla_,SLOT(setSaturation(int)));

    //Insercción de los elementos en el layout

    QBoxLayout* Sliders = new QBoxLayout(QBoxLayout::LeftToRight,this);
    Sliders -> addWidget(Brillo_, 0,0);
    Sliders -> addWidget(Contraste_,0, 0);
    Sliders -> addWidget(Saturacion_,0, 0);

    //ImagenLayout_->addWidget(nombre1_,2,2,0,0);
    //ImagenLayout_->addWidget(nombre2_, 2, 2, 1,0);
    //ImagenLayout_->addWidget(nombre3_, 2, 3, 1,0);


    //ImagenLayout_->addWidget(titulo_,0,0,1,0);
    //ImagenLayout_->addLayout(Sliders,1,1,0,0);
    //ImagenLayout_->addWidget(titulo_,2,1,0,0);

}

ImagenWIndow::~ImagenWIndow(){}

void ImagenWIndow::Controles(){
   exec();
}

