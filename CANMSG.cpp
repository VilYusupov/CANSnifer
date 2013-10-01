/*
 * CANMSG.cpp
 *
 *  Created on: 26.10.2011
 *      Author: Виль
 */

#include "CANMSG.h"

CANMSG::CANMSG(vector<unsigned char> msg, int id) {
	// TODO Auto-generated constructor stub
	_msg = msg;
	_id = id;
}

CANMSG::~CANMSG() {
	// TODO Auto-generated destructor stub
}
