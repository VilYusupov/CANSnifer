#ifndef CANSNIFER_H
#define CANSNIFER_H

#include <QtGui/QWidget>
#include "ui_cansnifer.h"
#include "CanOperator.h"
#include "iCANMSGReciever.h"
#include <QTextEdit>
#include <QLineEdit>
#include <QMutex>
#include <QQueue>
#include <QTime>
#include "iMsgHandler.h"
#include <QVector>
class CANSnifer : public QWidget, public iCANMSGReciever
{
    Q_OBJECT

    CanOperator * _can_operator;
    QTextEdit *_text_edit;
    QLineEdit *_line_edit;
    QLineEdit *_response_edit;
    QMutex _mutex;
    QQueue<iCANMSG*> _msges;
    int _counter;
    double _omega;
    QTime _timer;
    double _amp;
    unsigned char peredacha;
    QVector<iMsgHandler*> _handlers;
public:
    CANSnifer(QWidget *parent = 0);
    virtual void SetCANMSG(iCANMSG* canmsg);
    ~CANSnifer();
public slots:
	void slotGetMessage(iCANMSG *msg);
	void slotSetPeredacha();
protected:
    void timerEvent(QTimerEvent *event);
    virtual void closeEvent ( QCloseEvent * event );
private:
    Ui::CANSniferClass ui;
};

#endif // CANSNIFER_H
