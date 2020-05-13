#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QPixmap>
#include <QFileDialog>
#include <QAction>
#include <QTime>
#include <QVideoWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/resources/pics/380527.jpg");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString filter = "Audio file (*.mp3 *.vlc *.avi)";
    QString filePath = QFileDialog::getOpenFileName(this, "Select", "C:/Users/Lewis Mwirigi", filter);

    QMediaPlayer *player = new QMediaPlayer;
      player->setMedia(QUrl::fromLocalFile(filePath));
      player->play();

      ui->horizontalSlider_volume->setRange(0, 100);
      ui->horizontalSlider_volume->setValue(10);
      connect(ui->horizontalSlider_volume, SIGNAL(valueChanged(int)), player, SLOT(setVolume(int)));
      int v = ui->horizontalSlider_volume->value();
      QString volume; volume.setNum(v);
      ui->label_volume->setText(volume);

    connect(ui->actionPause, SIGNAL(triggered(bool)), player, SLOT(pause()));
         // ui->actionPause->setIcon(QIcon(":/resources/pics/play.png"));
    connect(ui->actionPlay, SIGNAL(triggered(bool)), player, SLOT(play()));

    connect(ui->actionStop, SIGNAL(triggered(bool)), player, SLOT(stop()));

}

void MainWindow::on_actionNew_Playlist_triggered()
{
    QString filter = "Audio file (*.mp3 *.vlc)";
    QMediaPlaylist *playlist = new QMediaPlaylist;
    QMediaPlayer *player = new QMediaPlayer;

    QStringList filePaths = QFileDialog::getOpenFileNames(this, "Select songs", "C:/Users/Lewis Mwirigi", filter);
    if(!filePaths.isEmpty())
    {
        for(int i=0; i<filePaths.count(); i++)
            playlist->addMedia(QUrl::fromLocalFile(filePaths.at(i)));

        ui->horizontalSlider_volume->setRange(0, 100);
        ui->horizontalSlider_volume->setValue(40);
        connect(ui->horizontalSlider_volume, SIGNAL(valueChanged(int)), player, SLOT(setVolume(int)));

        playlist->setCurrentIndex(1);
        player->setPlaylist(playlist);
        player->play();

        connect(ui->actionPause, SIGNAL(triggered(bool)), player, SLOT(pause()));

        connect(ui->actionPlay, SIGNAL(triggered(bool)), player, SLOT(play()));

        connect(ui->actionStop, SIGNAL(triggered(bool)), player, SLOT(stop()));

        connect(ui->actionNext, SIGNAL(triggered(bool)), playlist, SLOT(next()));

        connect(ui->actionPrevious, SIGNAL(triggered(bool)), playlist, SLOT(previous()));


    }

}
