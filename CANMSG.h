/*
 * CANMSG.h
 *
 *  Created on: 26.10.2011
 *      Author: Виль
 */

#ifndef CANMSG_H_
#define CANMSG_H_
#include <vector>
#include "iCANMSG.h"
using namespace std;
class CANMSG: public iCANMSG {
	int _id;
	vector<unsigned char> _msg;
public:
	virtual vector<unsigned char> *GetMsg(){return &_msg;}
	virtual int GetID(){return _id;}
	CANMSG(vector<unsigned char> msg, int id);

	virtual ~CANMSG();
};

#endif /* CANMSG_H_ */
