/*
 * iMsgHandler.h
 *
 *  Created on: 31.05.2013
 *      Author: Администратор
 */

#ifndef IMSGHANDLER_H_
#define IMSGHANDLER_H_
#include "iCANMSG.h"
#include <QString>
class iMsgHandler {
public:
	virtual bool setMsg(iCANMSG* msg) = 0;
	virtual QString getValue() = 0;
	virtual ~iMsgHandler(){}
};

#endif /* IMSGHANDLER_H_ */
