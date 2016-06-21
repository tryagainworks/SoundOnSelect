#ifndef MYQWIDGET_H
#define MYQWIDGET_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QVector>
#include <qdebug.h>
#include <QKeyEvent>
#include <QGridLayout>
#include <QLabel>
#include <QDir>
#include <QFileInfo>
#include <QApplication>
#include <QPixmap>
#include <QTransform>
#include <QMediaPlayer>
#include <QSysInfo>
#include <myqlabel.h>
#include <QMessageBox>
#include <clsglobal.h>

class myQWidget : public QWidget
{
    Q_OBJECT
public:
    explicit myQWidget(QWidget *parent = 0);

signals:

public slots:
    void onMyQLabelClicked(int intIndex);
public:
    void fnStartLoading(QString strSelectedFolder, int intImageInRow);
private:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    bool blnLoaded=false;
    void fnPlaySound(QString strFileName);
    QVector<QLabel*> vecLbl;
    QVector<QString> vecImgPth, vecSoundPth;
    void fnLoadImagePaths(QString strPath);
    const int intFixedSize=175;
    QMediaPlayer mplayer;
    void fnLoadSoundPaths(QString strPath);
    void fnCreateWidgetsAndLoadImages(int intColCount);
};

#endif // MYQWIDGET_H
