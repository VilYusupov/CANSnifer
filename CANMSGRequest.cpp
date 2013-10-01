/*
 * CANMSGRequest.cpp
 *
 *  Created on: 28.10.2011
 *      Author: Виль
 */

#include "CANMSGRequest.h"
#include "Logger.h"
CANMSGRequest::CANMSGRequest() {
	// TODO Auto-generated constructor stub

}
CANMSGRequest::CANMSGRequest(std::auto_ptr<iCANMSG> can_msg){
	Logger::GetLogger()->PutLine("CANMSGRequest::CANMSGRequest(std::auto_ptr<iCANMSG> can_msg","hay");
	_can_msg = can_msg;
	Logger::GetLogger()->PutLine("CANMSGRequest::CANMSGRequest(std::auto_ptr<iCANMSG> can_msg","hay1");
}
void CANMSGRequest::SetCANMSG(std::auto_ptr<iCANMSG> can_msg){
	Logger::GetLogger()->PutLine("void CANMSGRequest::SetCANMSG(std::auto_ptr<iCANMSG> can_msg)","hay");
	_can_msg = can_msg;
}
CANMSGRequest::CANMSGRequest(const CANMSGRequest &me){
	CANMSGRequest m = me;
	Logger::GetLogger()->PutLine("CANMSGRequest::CANMSGRequest(const CANMSGRequest &me)","hay");
	this->_can_msg = m._can_msg;

}
CANMSGRequest::~CANMSGRequest() {
	// TODO Auto-generated destructor stub
}
