/*
 * TemperatureHandler.h
 *
 *  Created on: 25.06.2013
 *      Author: Администратор
 */

#ifndef TEMPERATUREHANDLER_H_
#define TEMPERATUREHANDLER_H_
#include "../iMsgHandler.h"
#include "iDataParser.h"
#include <QFile>
class TemperatureHandler: public iMsgHandler {
	QFile _file;
	QString _value;
public:

	TemperatureHandler();
	virtual bool setMsg(iCANMSG* msg);
	virtual QString getValue();
	virtual ~TemperatureHandler();
};

#endif /* TEMPERATUREHANDLER_H_ */
