#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QStandardItemModel;
class QMediaPlaylist;
class QMediaPlayer;

class MainWindow :
        public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_add_clicked();
    void on_btn_right_clicked();
    void on_btn_start_clicked();
    void on_btn_pause_clicked();
    void on_btn_stop_clicked();
    void on_btn_left_clicked();
    void on_btn_mute_clicked();
    void on_sld_volume_valueChanged(int value);




    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow          *ui{nullptr};
    QStandardItemModel      *sti{nullptr};
    QMediaPlaylist          *mpl{nullptr};
    QMediaPlayer            *mpy{nullptr};

    int aa{0};
};

#endif // MAINWINDOW_H
