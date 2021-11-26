#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include <QDebug>

#include <QFileDialog>

// https://www.youtube.com/watch?v=AIPYc71zuck
// https://www.youtube.com/c/DuarteCorporationTutoriales/videos
// DuarteCorporation Tutoriales
// https://www.youtube.com/c/ProgrammingKnowledge/videos
// https://www.youtube.com/user/VoidRealms/videos

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sti = new QStandardItemModel;
    sti->setHorizontalHeaderLabels(QStringList()<<tr("Audio track")<<tr("File path"));
    ui->tableView->setModel(sti);

    //ui->tableView->hideColumn(1);    // Скрываем колонку, в которой хранится путь к файлу
    ui->tableView->verticalHeader()->setVisible(false);                  // Скрываем нумерацию строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);  // Включаем выделение строк
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); // Разрешаем выделять только одну строку
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);   // Отключаем редактирование
    // Включаем подгонку размера последней видимой колонки к ширине TableView
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    mpy = new QMediaPlayer(this);
    mpl = new QMediaPlaylist(mpy);
    mpy->setPlaylist(mpl);

    connect(mpy,&QMediaPlayer::positionChanged,[&](quint64 pos){
        ui->progressBar->setValue(pos);
        ui->horizontalSlider->setValue(pos);
    });
    connect(mpy,&QMediaPlayer::durationChanged,[&](quint64 dur){ ui->progressBar->setMaximum(dur);});

    // есть три варианта
    // 1 сконнектить напрямую сигнал со слотом
    // 2 сделать слоты для каждой кнопки и них вызывать слоты плейера
    // 3 сконнектить сигналы и слоты в самом дизайнере
//    connect(ui->btn_right, &QToolButton::clicked, m_playlist, &QMediaPlaylist::previous);
//    connect(ui->btn_left, &QToolButton::clicked, m_playlist, &QMediaPlaylist::next);
//    connect(ui->btn_start, &QToolButton::clicked, m_player, &QMediaPlayer::play);
//    connect(ui->btn_pause, &QToolButton::clicked, m_player, &QMediaPlayer::pause);
//    connect(ui->btn_stop, &QToolButton::clicked, m_player, &QMediaPlayer::stop);

    aa += 1;
}

//    QMediaPlaylist  *mpl{nullptr};
//    QStandardItem   *sti{nullptr};
//    QMediaPlayer    *mpy{nullptr};

MainWindow::~MainWindow()
{
    //qDebug()<<__PRETTY_FUNCTION__<<__LINE__;
    delete ui;
    if(sti != nullptr)   delete sti;
    if(mpy != nullptr)   delete mpy;
    //delete mpl;
    aa += 1;
    qDebug()<<__PRETTY_FUNCTION__<<__LINE__;
}


void MainWindow::on_btn_add_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this,tr("Open files"),QString(),tr("Audio Files (*.mp3)"));
       // Далее устанавливаем данные по именам и пути к файламв плейлист и таблицу отображающую плейлист
       for(auto & filePath : files) {
           QList<QStandardItem *> items;
           items.append(new QStandardItem(QDir(filePath).dirName()));
           items.append(new QStandardItem(filePath));
           sti->appendRow(items);
           mpl->addMedia(QUrl::fromLocalFile(filePath));
       }
   // qDebug()<<__PRETTY_FUNCTION__<<__LINE__;

//       for (auto _container_ = QtPrivate::qMakeForeachContainer(files);
//            _container_.control && _container_.i != _container_.e;
//            ++_container_.i, _container_.control ^= 1)
//           for (QString filePath = *_containe``r_.i; _container_.control; _container_.control = 0)
}

void MainWindow::on_btn_right_clicked()
{
    mpl->next();
}

void MainWindow::on_btn_left_clicked()
{
    mpl->previous();
}

void MainWindow::on_btn_start_clicked()
{
    mpy->play();
}

void MainWindow::on_btn_pause_clicked()
{
    mpy->pause();
}

void MainWindow::on_btn_stop_clicked()
{
    mpy->stop();
}

void MainWindow::on_btn_mute_clicked()
{
    if(ui->btn_mute->text() == "Mute"){
        mpy->setMuted(true);
        ui->btn_mute->setText("UnMute");
    }else{
        mpy->setMuted(false);
        ui->btn_mute->setText("Mute");
    }
}

void MainWindow::on_sld_volume_valueChanged(int value)
{
    mpy->setVolume(value);
}





void MainWindow::on_horizontalSlider_valueChanged(int value)
{
 //   ui->horizontalSlider->setValue(value);
}

