#ifndef MYQLABEL_H
#define MYQLABEL_H

#include <QObject>
#include <QLabel>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QEvent>
#include <QDebug>

class myQLabel : public QLabel
{
    Q_OBJECT
private:
    int intIndex;
    bool blnScrolled=false;
    bool blnTouchStarted=false;
public:
    explicit myQLabel(int _intIndex, QWidget *parent = 0);
protected:
    bool event(QEvent *e);
signals:
    void clicked(int intIndex);
};

#endif // MYQLABEL_H
