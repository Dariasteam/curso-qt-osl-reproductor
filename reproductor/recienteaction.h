#ifndef RECIENTEACTION_H
#define RECIENTEACTION_H

#include <QMediaPlayer>
#include <QAction>
#include <QString>

class RecienteAction : public QAction
{
    Q_OBJECT

public:
    explicit RecienteAction(QWidget*, QMediaPlayer*, QString);
    ~RecienteAction();

private:
    QMediaPlayer*      mediaPlayer_;
    QString            archivo_;

private slots:
    void Pulsar();
};

#endif // RECIENTEACTION_H
