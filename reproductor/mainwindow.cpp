#include <mainwindow.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //Create central widget and set main layout

    wgtMain_ = new QWidget(this);
    lytMain_ = new QGridLayout(wgtMain_);
    wgtMain_->setLayout(lytMain_);
    setCentralWidget(wgtMain_);

    mainMenu_ = new QMenuBar(this);
    Archivo_ = new QMenu(tr("Archivo"),this);
    Ayuda_  = new QMenu(tr("Ayuda"),this);
    Ver_    = new QMenu(tr("Ver"),this);
    Editar_ = new QMenu(tr("Editar"),this);

    setMenuBar(mainMenu_);
    mainMenu_->addMenu(Archivo_);
    mainMenu_->addMenu(Ver_);
    mainMenu_->addMenu(Editar_);
    mainMenu_->addMenu(Ayuda_);

    Abrir_ = new QAction(tr("Abrir"),this);
    Recientes_ = new QMenu(tr("Recientes"),this);
    AcercaDe_ = new QAction(tr("Acerca De"),this);
    FullScreen_ = new QAction(tr("Pantalla Completa"),this);
    //FullScreen_->setShortcut(QKeySequence(Qt::Escape));
    Metadatos_ = new QAction(tr("Metadatos"),this);
    Imagen_ = new QAction(tr("Imagen"),this);


    Archivo_->addAction(Abrir_);
    Archivo_->addMenu(Recientes_);
    Ayuda_->addAction(AcercaDe_);
    Ver_->addAction(FullScreen_);
    Ver_->addAction(Metadatos_);
    Editar_->addAction(Imagen_);


    //Initialize widgets
    mediaPlayer_  = new QMediaPlayer(this);
    playerSlider_ = new QSlider(Qt::Horizontal, this);
    videoWidget_  = new QVideoWidget(this);
    volumeSlider_ = new QSlider(Qt::Horizontal, this);
    btnOpen_      = new QToolButton(this);
    btnPlay_      = new QToolButton(this);
    btnPause_     = new QToolButton(this);
    btnStop_      = new QToolButton(this);
    Controles_ = new ImagenWIndow(this,videoWidget_);
    Ventana_ = new AcercaDeWindow(this);

    MetadatosW_=new MetadatosWindow(mediaPlayer_);

    //Setup widwgets
    videoWidget_->setMinimumSize(400, 400);
    mediaPlayer_->setVideoOutput(videoWidget_);
    mediaPlayer_->setVolume(100);
    videoWidget_->setAspectRatioMode(Qt::KeepAspectRatio);
    volumeSlider_->setRange(0, 100);
    volumeSlider_->setSliderPosition(100);

    //Play/Pause con shortcut

    //Populate grid layout
    lytMain_->addWidget(videoWidget_,  0, 0, 1, 5);
    lytMain_->addWidget(playerSlider_, 1, 0, 1, 5);
    lytMain_->addWidget(btnOpen_,      2, 0, 1, 1);
    lytMain_->addWidget(btnPlay_,      2, 1, 1, 1);
    lytMain_->addWidget(btnPause_,     2, 2, 1, 1);
    lytMain_->addWidget(btnStop_,      2, 3, 1, 1);
    lytMain_->addWidget(volumeSlider_, 2, 4, 1, 1);

    //Buttons icons
    btnOpen_->setIcon(QIcon(QPixmap(":/icons/resources/eject.png")));
    btnPause_->setIcon(QIcon(QPixmap(":/icons/resources/pause.png")));
    btnPlay_->setIcon(QIcon(QPixmap(":/icons/resources/play.png")));
    btnStop_->setIcon(QIcon(QPixmap(":/icons/resources/stop.png")));

    //Connections
    connect(Abrir_,        SIGNAL(triggered()),             this,         SLOT(onOpen()));
    connect(btnOpen_,      SIGNAL(pressed()),               this,         SLOT(onOpen()));
    connect(AcercaDe_,     SIGNAL(triggered()),             Ventana_,     SLOT(LeerAcercaDe()));
    connect(Imagen_,       SIGNAL(triggered()),             Controles_,   SLOT(Controles()));
    connect(FullScreen_,   SIGNAL(triggered()),             this,         SLOT(Max_Min()));
    connect(btnPlay_,      SIGNAL(pressed()),               mediaPlayer_, SLOT(play()));
    connect(btnPause_,     SIGNAL(pressed()),               mediaPlayer_, SLOT(pause()));
    connect(btnStop_,      SIGNAL(pressed()),               mediaPlayer_, SLOT(stop()));
    connect(playerSlider_, SIGNAL(sliderReleased()),        this,         SLOT(onSeek()));
    connect(mediaPlayer_,  SIGNAL(durationChanged(qint64)), this,         SLOT(onDurationChanged(qint64)));
    connect(mediaPlayer_,  SIGNAL(positionChanged(qint64)), this,         SLOT(onPositionChanged(qint64)));
    connect(volumeSlider_, SIGNAL(sliderMoved(int)),        this,         SLOT(onVolumeChanged(int)));
    connect(Metadatos_,    SIGNAL(triggered()),             MetadatosW_,  SLOT(MostrarMetadatos()));
}

MainWindow::~MainWindow()
{}

void MainWindow::onOpen()
{

    //Show file open dialog
    QString fileName = QFileDialog::getOpenFileName(this,tr("Abrir archivo"));
    if (fileName != "") {
        GuardarRecientes(fileName);
        mediaPlayer_->setMedia(QUrl::fromLocalFile(fileName));
        //mediaPlayer_->setMedia(QUrl("http://qthttp.apple.com.edgesuite.net/1010qwoeiuryfg/sl.m3u8"));
        mediaPlayer_->play();
        playing_=true;
    }
}

void MainWindow::onSeek()
{
    mediaPlayer_->setPosition(playerSlider_->sliderPosition());
}

void MainWindow::onDurationChanged(qint64 duration)
{
    playerSlider_->setRange(0, duration);
}

void MainWindow::onPositionChanged(qint64 position)
{
    playerSlider_->setSliderPosition(position);
}

void MainWindow::onVolumeChanged(int volume)
{
    mediaPlayer_->setVolume(volume);
}

void MainWindow::playPause(){
    qDebug() << "aa";
    if(playing_){
        mediaPlayer_->pause();
        playing_=false;
    }else{
        mediaPlayer_->play();
        playing_=true;
    }
}

void MainWindow::Max_Min()
{
    videoWidget_->setFullScreen(!isFullScreen());
}

void MainWindow::onOpenRecent(QString fileName){
    if (fileName != "") {
        mediaPlayer_->setMedia(QUrl::fromLocalFile(fileName));
        mediaPlayer_->play();
    }
}

void MainWindow::LeerRecientes(){
    QFile* archivo = new QFile;
    archivo->setFileName("recientes.txt");
    if(archivo->open(QFile::ReadOnly)){
        Reciente_v = new RecienteAction*[3];
        Reciente_s = new QAction*[3];
        for(int i=0;i<3;i++){
            char buf[1000];
            qint64 lineLength = archivo->readLine(buf, sizeof(buf));
            if (lineLength != -1) {
                QString A (buf);
                Reciente_v[i] = new RecienteAction(this,mediaPlayer_,A);
                Reciente_s[i] = new QAction(buf,this);
                Recientes_->addAction(Reciente_s[i]);
                connect(Reciente_s[i], SIGNAL(triggered()), Reciente_v[i], SLOT(Pulsar()));
            }
        }
    archivo->close();
    }
}

void MainWindow::GuardarRecientes(QString nuevo){
     QFile reciente("recientes.txt");
     if(reciente.exists()){
        QTextStream in (&reciente);
        if (!reciente.open(QIODevice::ReadWrite | QIODevice::Text)){
            return;
        }else{
            while (!in.atEnd()) {
                in.readAll();
            }
            in << QUrl::fromLocalFile(nuevo).toEncoded()<<"\n";
            reciente.close();
        }
     }
}
