/*
 * Logger.h
 *
 *  Created on: 21.08.2011
 *      Author: Виль
 */

#ifndef LOGGER_H_
#define LOGGER_H_
#include <QThread>

#include <QFile>
#include <QString>
#include <QQueue>
#include <QMutex>
#include "LoggerMessage.h"


class Logger: public QThread {
	QFile _file;
	static Logger *_me;
	static QString _file_name;
	QQueue<LoggerMessage> msges;
	QMutex mutex;
public:
	static Logger *GetLogger();
	static  void Kill();
	static void SetFileName(QString file_name);
	void PutLine(QString tag, QString msg);
	Logger();
	virtual ~Logger();
protected:
	void run();
};

#endif /* LOGGER_H_ */
