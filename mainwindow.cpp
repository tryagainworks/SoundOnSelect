#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScroller>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
    QScroller::grabGesture(ui->scrollArea, QScroller::TouchGesture);
    fnLoadDirectory();
}


void MainWindow::fnLoadDirectory(){
    QDir dir;
    dir = QDir(clsGlobal::fnGetBasePath());
    QStringList strDirLst =  dir.entryList(QDir::Dirs);
    if(strDirLst.count()>0){
    for(QString str : strDirLst){
        if(str!="." && str!="..")
        ui->cboDirNames->addItem(str);
    }
    ui->cboDirNames->setCurrentIndex(0);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Back){
        this->close();
    }
}

void MainWindow::on_cmd1_clicked()
{
    myQWidget *scrlwidget = (myQWidget*)ui->scrollcontentwidget;
    fnClearCtrls();
    scrlwidget->fnStartLoading(strSelectedDirectory, 1);
}

void MainWindow::on_cmd2_clicked()
{
    myQWidget *scrlwidget = (myQWidget*)ui->scrollcontentwidget;
    fnClearCtrls();
    scrlwidget->fnStartLoading(strSelectedDirectory,2);
}

void MainWindow::on_cmd3_clicked()
{
    myQWidget *scrlwidget = (myQWidget*)ui->scrollcontentwidget;
    fnClearCtrls();
    scrlwidget->fnStartLoading(strSelectedDirectory,3);
}

void MainWindow::fnClearCtrls(){
    ui->cmd1->close();
    ui->cmd2->close();
    ui->cmd3->close();
    ui->label->close();
    ui->label_2->close();
    ui->cboDirNames->close();
    delete ui->scrollcontentwidget->layout();
}


void MainWindow::on_cboDirNames_currentIndexChanged(const QString &arg1)
{
    strSelectedDirectory = arg1;
}
