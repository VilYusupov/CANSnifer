/*
 * CanOperator.h
 *
 *  Created on: 28.10.2011
 *      Author: Виль
 */

#ifndef CANOPERATOR_H_
#define CANOPERATOR_H_
#include <QThread>
#include <QMutex>
#include <QQueue>
#include "CANMSGRequest.h"
#include <memory>
#include "vs_can_api.h"
#include "iCANMSGReciever.h"
using namespace std;
class CanOperator: public QThread {
	Q_OBJECT
	QMutex mutex;
	QQueue<iCANMSG*> _msgs;
	QString _com_name;
	VSCAN_HANDLE _handle;
	bool _to_stop;
	iCANMSGReciever* _reciever;
public:
	void AddCANMSG(iCANMSG* msg);
	CanOperator(iCANMSGReciever* reciever);
	void setCOMName(QString com_name);
	virtual ~CanOperator();
signals:
	void signCANMSG(iCANMSG *msg);
protected:
	void run();
};

#endif /* CANOPERATOR_H_ */
