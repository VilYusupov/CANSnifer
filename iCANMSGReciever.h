/*
 * iCANMSGReciever.h
 *
 *  Created on: 26.10.2011
 *      Author: Виль
 */

#ifndef ICANMSGRECIEVER_H_
#define ICANMSGRECIEVER_H_
#include "iCANMSG.h"
//#include <memory>
class iCANMSGReciever {
public:
	virtual void SetCANMSG(iCANMSG* canmsg) = 0;
	virtual ~iCANMSGReciever(){}
};

#endif /* ICANMSGRECIEVER_H_ */
