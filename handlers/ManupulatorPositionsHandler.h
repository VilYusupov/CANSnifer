/*
 * ManupulatorPositionsHandler.h
 *
 *  Created on: 31.05.2013
 *      Author: Администратор
 */

#ifndef MANUPULATORPOSITIONSHANDLER_H_
#define MANUPULATORPOSITIONSHANDLER_H_
#include "../iMsgHandler.h"
#include "iDataParser.h"
#include <QFile>
class ManupulatorPositionsHandler: public iMsgHandler {
	QFile _file;
	iDataParser *_sub_handler;
	int _id;
public:
	ManupulatorPositionsHandler();
	ManupulatorPositionsHandler(int id);
	ManupulatorPositionsHandler(int id, iDataParser  *sub_handler);
	void setID(int id){_id = id;}
	virtual bool setMsg(iCANMSG* msg);
	virtual QString getValue(){return QString::fromUtf8("hay");}
	virtual ~ManupulatorPositionsHandler();

};

#endif /* MANUPULATORPOSITIONSHANDLER_H_ */
