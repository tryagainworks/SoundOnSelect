#include "myqlabel.h"

myQLabel::myQLabel(int _intIndex, QWidget *parent) :
	QLabel(parent)
{
	intIndex = _intIndex;
}

bool myQLabel::event(QEvent *e)
{
	qDebug()<<e->type();
    if(e->type()==e->MouseButtonPress || e->type()==e->TouchBegin)
    {
        //both mousebutton press and touchbegin happen all the times when in android
        blnTouchStarted=true;
    }
    else if(e->type()==e->MouseMove)
	{
		blnScrolled=true;
	}
    else if((e->type()==e->TouchEnd || e->type()==e->MouseButtonRelease) && blnTouchStarted)
	{
        //to avoid re entering this block
        //because both the touchend and mousebuttonrelease event happen all times when in android
        blnTouchStarted=false;
		if(!blnScrolled)
		{
			emit clicked(intIndex);
		}
		else
		{
			blnScrolled=false;
		}

	}

	QLabel::event(e);
}
