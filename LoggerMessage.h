/*
 * LoggerMessage.h
 *
 *  Created on: 25.08.2011
 *      Author: Виль
 */

#ifndef LOGGERMESSAGE_H_
#define LOGGERMESSAGE_H_
#include <QString>
class LoggerMessage {
	QString _tag, _msg;
public:
	LoggerMessage(){}
	LoggerMessage(QString tag, QString msg);
	QString GetTag(){return _tag;}
	QString GetMsg(){return _msg;}
	virtual ~LoggerMessage();
};

#endif /* LOGGERMESSAGE_H_ */
