#include "mainwindow.h"
#include "ui_mainwindow.h"

QHash<QString, QString>
        fileHash;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Set Open Files Button Slot
    this->connect(this->ui->btnOpenFiles, SIGNAL(clicked()), this, SLOT(OpenFiles()));
    //this->connect(this->ui->btnExit, SIGNAL(clicked()), this, SLOT(Exit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::Exit(){

//    close();
//    qApp->quit();

//}

void MainWindow::on_btnExit_clicked()
{
    close();
    qApp->quit();
}

void MainWindow::OpenFiles()
{
    QStringList
            fileNames;

    qDebug() << "you just clicked ok";

    fileNames = QFileDialog::getOpenFileNames(this, tr("Open File"),"/home/",tr("*.*"));

    for (QString & fileName : fileNames)
    {
        fileHash.insert(QFileInfo(QFile(fileName).fileName()).fileName(), fileName);
        ui->listWidget->addItem(QFileInfo(QFile(fileName).fileName()).fileName()); 
//        QMediaObject file = QMediaObject()
//        QMediaContent file = QMediaContent(fileName);
//        QString title = file(QMediaMetaData::Title);
    }

    //ui->listWidget->addItems(fileNames);
}
