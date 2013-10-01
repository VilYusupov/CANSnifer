/*
 * TemperatureHandler.cpp
 *
 *  Created on: 25.06.2013
 *      Author: Администратор
 */

#include "TemperatureHandler.h"
#include <QVector>
#include "Logger.h"
TemperatureHandler::TemperatureHandler() {
	// TODO Auto-generated constructor stub
	_file.setFileName("temp.txt");
	_file.open(QIODevice::WriteOnly);
}
bool TemperatureHandler::setMsg(iCANMSG* msg){
	if (msg->GetID()!=0x413) return false;

	QVector<int> values;
	values.resize(4);
	for (int i = 0; i<4; i++) {
		unsigned char mask = 0;
		for (int j = 0; j< 8-i*2; j++) {
			mask |= 1 << j;
		}
		values[i] = ( (msg->GetMsg()->at(10*i/8+1)) & (mask)) << ((i+1)*2);
		Logger::GetLogger()->PutLine("temp nb", QString::number(10*i/8+1));
		Logger::GetLogger()->PutLine("temp mask",QString::number(mask));
		Logger::GetLogger()->PutLine("temp val",QString::number( (msg->GetMsg()->at(10*i/8+1)) & (mask)));
		values[i] |= ((msg->GetMsg()->at(10*i/8+2)) >> (6-i*2));// & (~(1 << ( 2*(i+1) )));

		if (values[i]>512) {
			values[i] &= ~0x200;
			values[i] = - values[i];
		}
	}
	QString str;
	for (int i = 0; i<4; i++) {
		str.append(QString::number(values[i]));
		str.append(" ");
	}
	_value = str;
	str.append("\n");

	_file.write(str.toAscii());
	return true;
}
QString TemperatureHandler::getValue(){
	return _value;
}
TemperatureHandler::~TemperatureHandler() {
	// TODO Auto-generated destructor stub
	_file.close();
}

