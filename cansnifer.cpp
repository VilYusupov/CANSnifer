#define pi 3.14159265
#include "cansnifer.h"

#include "Logger.h"
#include <QHBoxLayout>
#include <vector>
#include <cmath>
#include "CANMSG.h"
#include <QPushButton>
#include <QMessageBox>
#include "handlers/ManupulatorPositionsHandler.h"
#include "handlers/AbsPositionHandler.h"
#include "handlers/TemperatureHandler.h"
#define PI 3.141592
using namespace std;
CANSnifer::CANSnifer(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	_can_operator = new CanOperator(this);
	QObject::connect(_can_operator, SIGNAL(signCANMSG(iCANMSG*)),this, SLOT(slotGetMessage(iCANMSG*)));
	//_text_edit = new QTextEdit(this);
	_line_edit = new QLineEdit;
	_response_edit = new QLineEdit;
	Logger::GetLogger()->PutLine("size_of_int", QString::number(sizeof(int)));
	QHBoxLayout *_layout = new QHBoxLayout();
	_layout->addWidget(_line_edit);
	_layout->addWidget(_response_edit);
	QPushButton *button = new QPushButton;
	QObject::connect(button, SIGNAL(clicked()),this, SLOT( slotSetPeredacha()));
	_layout->addWidget(button);
	setLayout(_layout);
	_counter = 2;
	startTimer(100);
	_omega = 4*pi;
	 _amp = 100;
	_timer = QTime::currentTime();
	_timer.start();
	peredacha = 0;


	/*_handlers.append(new ManupulatorPositionsHandler(32));
	_handlers.append( new ManupulatorPositionsHandler(33));
	_handlers.append( new ManupulatorPositionsHandler(36,new AbsPositionHandler()));
	_handlers.append( new ManupulatorPositionsHandler(34,new AbsPositionHandler()));
	_handlers.append( new ManupulatorPositionsHandler(35,new AbsPositionHandler()));*/

	_handlers.append(new TemperatureHandler());
}
void CANSnifer::slotGetMessage(iCANMSG *msg){
	QString tag;
	tag = "ID=";
	tag.append(QString::number(msg->GetID(),16));
	QString message_string;
	for (unsigned int i = 0 ; i<msg->GetMsg()->size();i++) {
		message_string.append(QString::number(msg->GetMsg()->at(i),16));
		message_string.append(" ");
	}
	int pos=0;
	if ((msg->GetID()>=0x401) && (msg->GetID()<0x405)) {
		pos = (msg->GetMsg()->at(3) << 2) | (msg->GetMsg()->at(4) >> 6);
		message_string = message_string.append(" p:").append(QString::number(pos));
	}
	Logger::GetLogger()->PutLine(tag,message_string);
	QString str;
	str.append(tag);
	str.append(":");
	str.append(message_string);
	//_text_edit->append(str);
	//_response_edit->setText(str);
	if (msg->GetID()==0x404) Logger::GetLogger()->PutLine("p",QString::number(pos));
	for (int i = 0; i< _handlers.size(); i++) if (_handlers[i]->setMsg(msg)){
		_response_edit->setText(_handlers[i]->getValue());
	}
	delete msg;
}
void CANSnifer::timerEvent(QTimerEvent *event){
	int id = 0x13;//0xe;
	vector<unsigned char> msg;
	unsigned char p = peredacha;
	msg.resize(5);
	msg[0] = 0x3;
	msg[1] = 2;
	msg[2] = 0;
	msg[3] = 0;
	msg[4] = 0;


	//msg[1] = (1 << 4) | 1;
	//msg[2] = 0;

	/*if (p>128) {
		p = 256-p;
		p |= 0x80;
		//Logger::GetLogger()->PutLine("wdwewew",QString::number(p,2));
	}*/
	/*msg[2] = p;
	msg[3] = 0;
	msg[4] = 0;
	msg[5] = 0;
	msg[6] = 0;
	msg[7] = 0;*/



	CANMSG *can_msg = new CANMSG(msg, id);
	_can_operator->AddCANMSG(can_msg);

	//msg.push_back(0x1);
	//char cv = _amp*sin((double)(_timer.elapsed())/1000*_omega);
	//if (cv<0)
	//	msg.push_back(-cv + 0x80);
	//else
		//msg.push_back(cv);
	//msg.push_back(0xC0)
	//id = 0x1c5e2e3a;

	//int angle = (500/6/2);
	//msg.push_back(20);
	//msg.push_back((char)(angle & 0xff));
	//msg.push_back((char)((angle >> 8) & 0xff));
	//msg.push_back(0);
	//msg.push_back(0);
	//msg.push_back(0);
	//msg.push_back(0);
	//msg.push_back(0);
	//msg.push_back(peredacha);
	//msg.push_back(_counter);

	//int id = 0x5c6e2fa;
	/*vector<unsigned char> msg;
	msg.push_back(3);
	msg.push_back((1 << 4) | peredacha);
	//msg.push_back(peredacha);
	msg.push_back(0);
	msg.push_back(0);
	msg.push_back(0);*/
/*
	CANMSG *can_msg = new CANMSG(msg, id);
	_can_operator->AddCANMSG(can_msg);
	msg.clear();
	id = 100;
	angle = (500/6/2);
	msg.push_back(20);
	msg.push_back((char)(angle & 0xff));
	msg.push_back((char)((angle >> 8) & 0xff));
	msg.push_back(0);
	msg.push_back(0);
	msg.push_back(0);
	msg.push_back(0);
	msg.push_back(0);
	can_msg = new CANMSG(msg, id);
	_can_operator->AddCANMSG(can_msg);

	msg.clear();
	id = 102;
	angle = (500/3/2);
	msg.push_back(20);
	msg.push_back((char)(angle & 0xff));
	msg.push_back((char)((angle >> 8) & 0xff));
	msg.push_back(0);
	msg.push_back(0);
	msg.push_back(0);
	msg.push_back(0);
	msg.push_back(0);
	can_msg = new CANMSG(msg, id);
	_can_operator->AddCANMSG(can_msg);

	msg.clear();
	id = 103;
	angle = (500/4/2);
	msg.push_back(20);
	msg.push_back((char)(angle & 0xff));
	msg.push_back((char)((angle >> 8) & 0xff));
	msg.push_back(0);
	msg.push_back(0);
	msg.push_back(0);
	msg.push_back(0);
	msg.push_back(0);
	can_msg = new CANMSG(msg, id);
	_can_operator->AddCANMSG(can_msg);
*/
	//Logger::GetLogger()->PutLine("void CANSnifer::timerEvent(QTimerEvent *event)", QString::number(msg[1]));
	if (_counter == 2) _counter = 0; else _counter = 2;
	/*while (!_msges.isEmpty())  {
		_mutex.lock();
		iCANMSG* canmsg = _msges.dequeue();
		_mutex.unlock();
		slotGetMessage(canmsg);

	}*/
	//_response_edit->setText("");

}
void CANSnifer::SetCANMSG(iCANMSG* canmsg){
    _mutex.lock();
    _msges.enqueue(canmsg);
    _mutex.unlock();
}
void CANSnifer::slotSetPeredacha(){
	peredacha = _line_edit->text().toInt(0,10);

	//Logger::GetLogger()->PutLine("void CANSnifer::slotSetPeredacha()",QString::number(peredacha));
}
void CANSnifer::closeEvent ( QCloseEvent * event ){

}
CANSnifer::~CANSnifer()
{
	for (int i = 0; i<_handlers.size();i++) delete _handlers[i];
	_handlers.clear();
	delete _can_operator;
}
