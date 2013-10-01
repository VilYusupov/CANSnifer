/*
 * CanOperator.cpp
 *
 *  Created on: 28.10.2011
 *      Author: Виль
 */

#include "CanOperator.h"
#include "Logger.h"
#include "CANMSG.h"
#include <vector>
//#include <QTime>
using namespace std;
CanOperator::CanOperator(iCANMSGReciever* reciever) {
	// TODO Auto-generated constructor stub
	_com_name = "COM18";

	//char *str = _com_name.toAscii().data();
	_handle = VSCAN_Open(_com_name.toAscii().data(), VSCAN_MODE_NORMAL);
	if (!_handle) {
		Logger::GetLogger()->PutLine("CanOperator::CanOperator()", "ERR_VSCOM");
	}
	VSCAN_BTR btr;
	btr.Btr0 = 69;
	btr.Btr1 = 28;
	//VSCAN_Ioctl(_handle, VSCAN_IOCTL_SET_BTR, &btr);
	VSCAN_STATUS status = VSCAN_Ioctl(_handle, VSCAN_IOCTL_SET_SPEED, VSCAN_SPEED_250K);
	char err_msg[32];
	VSCAN_GetErrorString(status, err_msg, 32);
	if (status)
			Logger::GetLogger()->PutLine("CanOperator::CanOperator(iCANMSGReciever* reciever)",QString::fromAscii(err_msg,32));

	_to_stop = false;
	_reciever = reciever;
	start();
}
void CanOperator::AddCANMSG(iCANMSG *msg){
	QMutexLocker locker(&mutex);
	//Logger::GetLogger()->PutLine("void CanOperator::AddCANMSG(std::auto_ptr<iCANMSG> msg)","hay");
	_msgs.enqueue(msg);
	//Logger::GetLogger()->PutLine("void CanOperator::AddCANMSG(std::auto_ptr<iCANMSG> msg)","hay1");
	/*if (!isRunning())
		start();*/
}
void CanOperator::CanOperator::run(){
	iCANMSG *msg = 0;
	VSCAN_STATUS status = 1;
//	QTime time = QTime::currentTime();

	forever {
		mutex.lock();
		if (_to_stop) break;
		if (!_msgs.isEmpty()) {
			msg = _msgs.dequeue();
			mutex.unlock();
			DWORD writen;
			VSCAN_MSG msgs;
			QString str;
			//Logger::GetLogger()->PutLine("void CanOperator::CanOperator::run(), CAN_T_MSG","HAY");
			for (unsigned int i = 0; i<msg->GetMsg()->size();i++) {
				msgs.Data[i] = msg->GetMsg()->at(i);
				str = str.append(QString::number(msgs.Data[i],10)).append(" ");
			}
			//Logger::GetLogger()->PutLine("void CanOperator::CanOperator::run(), CAN_T_MSG",str);
			msgs.Id = msg->GetID();
			//Logger::GetLogger()->PutLine("id", QString::number(msgs.Id,16));
			//msgs.Flags = VSCAN_FLAGS_EXTENDED;
			msgs.Flags = VSCAN_FLAGS_STANDARD;
			msgs.Size = msg->GetMsg()->size();
			//Logger::GetLogger()->PutLine("msges_size", QString::number(msgs.Size));
			status = 0;
			status =VSCAN_Write(_handle, &msgs, 1, &writen);
			char err_msg[32];
			VSCAN_GetErrorString(status, err_msg, 32);
			//if (status)
			//Logger::GetLogger()->PutLine("void CanOperator::CanOperator::run(), CAN_T_MSG",QString::fromAscii(err_msg,32));
			delete msg;
		}
		else mutex.unlock();

		VSCAN_MSG buf;
		buf.Size = 0;
		DWORD red;

		//buf.Size = 8;


		status = VSCAN_Read(_handle, &buf, 1, &red);
		if (status!=0){
			char err_msg[32];
			VSCAN_GetErrorString(status, err_msg, 32);
			//Logger::GetLogger()->PutLine("void CanOperator::CanOperator::run(), CAN_R_MSG",QString::fromAscii(err_msg,32));
		}
		if ((buf.Size>0) && (status==0)){
		//VSCAN_Flush(_handle);
			if (status==0){
				char err_msg[32];
				VSCAN_GetErrorString(status, err_msg, 32);
				//Logger::GetLogger()->PutLine("void CanOperator::CanOperator::run(), CAN_T_MSG",QString::fromAscii(err_msg,32));
			}
			if ((status==0)) {
				status = 1;
				vector<unsigned char> msg_data;
				msg_data.resize(buf.Size);
				QString str;
				for (unsigned int i = 0; i<buf.Size;i++){
					msg_data[i] = buf.Data[i];
					str = str.append(QString::number(buf.Data[i],10)).append(" ");
				}

				//char command_speed = msg_data[1];
				//char current_speed = msg_data[2];
				//Logger::GetLogger()->PutLine("recieved message", str);
				//Logger::GetLogger()->PutLine(QString::number(command_speed), QString::number(current_speed));
				CANMSG *can_msg =  new CANMSG(msg_data, buf.Id);
				//_reciever->SetCANMSG(can_msg);
				emit signCANMSG(can_msg);
			}
			//status = VSCAN_Read(_handle, &buf, 1, &red);
		}
			/*for (int id = 100;id<104; id++){
				vector<unsigned char> msg_data;
				msg_data.resize(8);
				msg_data[0] = 20;
				msg_data[1] = 2;
				msg_data[2] = 128;

				CANMSG *can_msg =  new CANMSG(msg_data, id);

				emit signCANMSG(can_msg);
			}*/

			/*vector<unsigned char> msg_data;
			//float _m_pi = 3.141592;
			int16_t angle;
			msg_data.resize(8);
			angle = (500/6/2);
			msg_data[1] = angle & 255;
			msg_data[2] = angle >> 8;
			msg_data[0] = 20;
			CANMSG *can_msg =  new CANMSG(msg_data, 100);
			emit signCANMSG(can_msg);
			angle = (500/6/2);
			msg_data[1] = angle & 255;
			msg_data[2] = angle >> 8;
			msg_data[0] = 20;
			can_msg =  new CANMSG(msg_data, 101);
			emit signCANMSG(can_msg);
			angle = (500/3/2);
			msg_data[1] = angle & 255;
			msg_data[2] = angle >> 8;
			msg_data[0] = 20;
			can_msg =  new CANMSG(msg_data, 102);
			emit signCANMSG(can_msg);
			angle = (500/4/2);
			msg_data[1] = angle & 255;
			msg_data[2] = angle >> 8;
			msg_data[0] = 20;
			can_msg =  new CANMSG(msg_data, 103);
			emit signCANMSG(can_msg);*/




	}
	while (!_msgs.isEmpty()) delete _msgs.dequeue();
	mutex.unlock();
}
void CanOperator::setCOMName(QString com_name){
	if (_handle) VSCAN_Close(_handle);
	_handle = VSCAN_Open(_com_name.toAscii().data(), VSCAN_MODE_NORMAL);
	if (!_handle) {
			Logger::GetLogger()->PutLine("CanOperator::CanOperator()", "ERR_VSCOM");
		}
	VSCAN_BTR btr;
	btr.Btr0 = 65;
	btr.Btr1 = 28;
	//VSCAN_Ioctl(_handle, VSCAN_IOCTL_SET_BTR, &btr);
	VSCAN_Ioctl(_handle, VSCAN_IOCTL_SET_SPEED, VSCAN_SPEED_250K);
	_to_stop = false;
	//_reciever = reciever;
	start();
}
CanOperator::~CanOperator() {
	// TODO Auto-generated destructor stub
	mutex.lock();
	_to_stop = true;
	mutex.unlock();
	VSCAN_Close(_handle);
	wait();
}
