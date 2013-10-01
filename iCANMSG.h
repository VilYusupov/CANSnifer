/*
 * iCANMSG.h
 *
 *  Created on: 26.10.2011
 *      Author: Виль
 */

#ifndef ICANMSG_H_
#define ICANMSG_H_
#include <vector>
using namespace std;
class iCANMSG {
public:
	virtual vector<unsigned char> *GetMsg() = 0;
	virtual int GetID() = 0;
};

#endif /* ICANMSG_H_ */
