/*
 * iDataParser.h
 *
 *  Created on: 01.06.2013
 *      Author: Администратор
 */

#ifndef IDATAPARSER_H_
#define IDATAPARSER_H_
#include <QString>
#include "../iCANMSG.h"
class iDataParser {
public:
	virtual QString getData(iCANMSG* msg) = 0;
	virtual ~iDataParser(){}
};

#endif /* IDATAPARSER_H_ */
