/*
 * iCANCoordinateReciever.h
 *
 *  Created on: 27.10.2011
 *      Author: Виль
 */

#ifndef ICANCOORDINATERECIEVER_H_
#define ICANCOORDINATERECIEVER_H_
#include "iCANMSGReciever.h"
//#include "DiscreteStream.h"
class iCANCoordinateReciever:public iCANMSGReciever {
public:

	virtual void SetCANMSG(iCANMSG *canmsg) = 0;
	virtual void SetID(int id) = 0;
};

#endif /* ICANCOORDINATERECIEVER_H_ */
