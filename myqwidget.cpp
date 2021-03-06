#include "myqwidget.h"
#include <QPushButton>
#include <QScroller>

myQWidget::myQWidget(QWidget *parent) : QWidget(parent)
{

}

void myQWidget::onMyQLabelClicked(int intIndex)
{
	qDebug()<<vecImgPth[intIndex];
	qDebug()<<vecSoundPth[intIndex];
	if(vecSoundPth[intIndex]!="")
	{
		fnPlaySound(vecSoundPth[intIndex]);
	}
}

void myQWidget::fnStartLoading(QString strSelectedFolder, int intImageInRow)
{
    if(!blnLoaded)
	{
        fnLoadImagePaths(strSelectedFolder);
        fnLoadSoundPaths(strSelectedFolder);
        fnCreateWidgetsAndLoadImages(intImageInRow);
        blnLoaded=true;
	}
}

void myQWidget::keyPressEvent(QKeyEvent *event)
{

}

void myQWidget::fnPlaySound(QString strFileName)
{
    //if(!(mplayer.state()==QMediaPlayer::PlayingState))
	//{
    mplayer.stop();
	mplayer.setMedia(QUrl::fromLocalFile(strFileName));
	mplayer.play();
	//}
}

void myQWidget::fnLoadImagePaths(QString strPath)
{
	QDir dir;
    dir = QDir(clsGlobal::fnGetBasePath() + strPath + "/Images");

	QStringList strLst= dir.entryList(QDir::Files);
	for(QString str : strLst)
	{
		qDebug()<<dir.absolutePath()+"/"+str;
		vecImgPth.push_back(dir.absolutePath()+"/"+str);
	}
}

void myQWidget::fnLoadSoundPaths(QString strPath)
{
	QDir dir;
    dir = QDir(clsGlobal::fnGetBasePath() + strPath + "/Sounds");

	QStringList strLst= dir.entryList(QDir::Files);

	QFileInfo file;
	for(int iCount=0; iCount<vecImgPth.count(); iCount++)
	{
		file = QFileInfo(vecImgPth[iCount]);
		qDebug()<<"Base Name="<<file.baseName();
        QStringList strLstTmp = strLst.filter(file.baseName() + ".mp3",Qt::CaseInsensitive);
		if(strLstTmp.count()!=0)
		{
			qDebug()<<dir.absolutePath()+"/"+strLstTmp.at(0);
			vecSoundPth.push_back(dir.absolutePath()+"/"+strLstTmp.at(0));
		}
		else
		{
			vecSoundPth.push_back("");
		}
	}
}

void myQWidget::mousePressEvent(QMouseEvent *event)
{
	//fnStartLoadingWidgets();
}

void myQWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	//QMessageBox::information(this,"title",QString::number(vecImgPth.count()));
	//fnStartLoadingWidgets();
}

void myQWidget::fnCreateWidgetsAndLoadImages(int intColCount)
{
	QGridLayout *grd = new QGridLayout(this);
	int iCount=0, iRow=0,iCol=0;
	int intImageWidth = this->width()/intColCount;
	for(int iCount=0; iCount<vecImgPth.count(); iCount++)
	{
		myQLabel *lbl = new myQLabel(iCount,this);
		lbl->setFixedSize(intImageWidth,intImageWidth);
		lbl->setScaledContents(true);
        //lbl->setAttribute(Qt::WA_AcceptTouchEvents);
		QScroller::grabGesture(lbl, QScroller::TouchGesture);
		lbl->setPixmap(QPixmap(vecImgPth[iCount]));
		if(iCol>(intColCount-1))
		{
			iRow++;
			iCol=0;
		}
		grd->addWidget(lbl,iRow,iCol++);
		connect(lbl,SIGNAL(clicked(int)),this,SLOT(onMyQLabelClicked(int)));
		vecLbl.push_back(lbl);
	}
	this->setLayout(grd);
}
