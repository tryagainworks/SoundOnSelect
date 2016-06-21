#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <clsglobal.h>

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
    void fnClearCtrls();
    void fnLoadDirectory();
    QString strSelectedDirectory;
protected:
    virtual void keyPressEvent(QKeyEvent *event);
private slots:
    void on_cmd1_clicked();
    void on_cmd2_clicked();
    void on_cmd3_clicked();
    void on_cboDirNames_currentIndexChanged(const QString &arg1);
};

#endif // MAINWINDOW_H
