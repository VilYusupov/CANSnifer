/*
 * AbsPositionHandler.h
 *
 *  Created on: 01.06.2013
 *      Author: Администратор
 */

#ifndef ABSPOSITIONHANDLER_H_
#define ABSPOSITIONHANDLER_H_
#include "iDataParser.h"
class AbsPositionHandler: public iDataParser {
public:
	AbsPositionHandler();
	virtual QString getData(iCANMSG* msg);
	virtual ~AbsPositionHandler();
};

#endif /* ABSPOSITIONHANDLER_H_ */
