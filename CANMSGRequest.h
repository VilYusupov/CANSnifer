/*
 * CANMSGRequest.h
 *
 *  Created on: 28.10.2011
 *      Author: Виль
 */

#ifndef CANMSGREQUEST_H_
#define CANMSGREQUEST_H_
#include "iCANMSG.h"
#include <memory>
using namespace std;
class CANMSGRequest {
	std::auto_ptr<iCANMSG> _can_msg;
public:
	CANMSGRequest(std::auto_ptr<iCANMSG> can_msg);
	CANMSGRequest();
	CANMSGRequest(const CANMSGRequest &me);
	void SetCANMSG(std::auto_ptr<iCANMSG> can_msg);

	std::auto_ptr<iCANMSG> GetCANMSG(){
		std::auto_ptr<iCANMSG> m = _can_msg;
		delete this;
		return m;
		}
	virtual ~CANMSGRequest();
};

#endif /* CANMSGREQUEST_H_ */
