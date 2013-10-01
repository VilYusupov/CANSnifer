/*
 * ManupulatorPositionsHandler.cpp
 *
 *  Created on: 31.05.2013
 *      Author: Администратор
 */

#include "ManupulatorPositionsHandler.h"
#include "../Logger.h"
ManupulatorPositionsHandler::ManupulatorPositionsHandler() {
	// TODO Auto-generated destructor stub
	_file.setFileName("positions.txt");
	_file.open(QIODevice::WriteOnly);
_id = 0;
	_sub_handler = 0;
}
ManupulatorPositionsHandler::ManupulatorPositionsHandler(int id, iDataParser  *sub_handler){
	QString file_name;
		file_name = "positions_";
		file_name = file_name.append(QString::number(id)).append(".txt");
		_file.setFileName(file_name);
		_file.open(QIODevice::WriteOnly);
		_id = id;
		_sub_handler = sub_handler;
}
ManupulatorPositionsHandler::ManupulatorPositionsHandler(int id) {
	// TODO Auto-generated destructor stub
	QString file_name;
	file_name = "positions_";
	file_name = file_name.append(QString::number(id)).append(".txt");
	_file.setFileName(file_name);
	_file.open(QIODevice::WriteOnly);
	_id = id;
	_sub_handler = 0;

}
bool ManupulatorPositionsHandler::setMsg(iCANMSG* msg){


	if (msg->GetID()!= _id) return false;
	QString str;
	if (_sub_handler == 0) {
	double pos=0;
	for (int i = 0; i<4; i++) {

		pos = ((int16_t)( ((int16_t)(msg->GetMsg()->at(i*2))) | ((int16_t)msg->GetMsg()->at(i*2+1) << 8))/1000.0 * 360);
		str = str.append(QString::number(pos)).append(";");
	}
	str.append("\r\n");
	} else str = _sub_handler->getData(msg);

	_file.write(str.toAscii());
	return true;
	//_file.close();
}
ManupulatorPositionsHandler::~ManupulatorPositionsHandler() {
	// TODO Auto-generated constructor stub
	_file.close();
	delete _sub_handler;
}

