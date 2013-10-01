/*
 * AbsPositionHandler.cpp
 *
 *  Created on: 01.06.2013
 *      Author: Администратор
 */

#include "AbsPositionHandler.h"

AbsPositionHandler::AbsPositionHandler() {
	// TODO Auto-generated constructor stub

}
QString AbsPositionHandler::getData(iCANMSG* msg){
	QString str;
	double pos=0;
	for (int i = 0; i<4; i++) {

	pos = ((int16_t)( ((int16_t)(msg->GetMsg()->at(i*2))) | ((int16_t)msg->GetMsg()->at(i*2+1) << 8)));
	str = str.append(QString::number(pos)).append(" ");
	}
	str.append("\r\n");
	return str;
}
AbsPositionHandler::~AbsPositionHandler() {
	// TODO Auto-generated destructor stub
}

