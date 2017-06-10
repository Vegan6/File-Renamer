#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>
#include <QFileDialog>
//#include <QMediaMetaData>
//#include <QMediaContent>
//#include <QMediaObject>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;

    private slots:
       // void Exit();
        void on_btnExit_clicked();
        void OpenFiles();
};

#endif // MAINWINDOW_H
