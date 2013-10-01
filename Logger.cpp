/*
 * Logger.cpp
 *
 *  Created on: 21.08.2011
 *      Author: ����
 */

#include "Logger.h"

Logger *Logger::_me = 0;
QString Logger::_file_name = "log.txt";

Logger::Logger() {
	// TODO Auto-generated constructor stub
	_file.setFileName(_file_name);
	_file.open(QIODevice::WriteOnly);
	_file.close();
	//_file.open(QIODevice::WriteOnly);
	//me = this;
}
Logger *Logger::GetLogger(){
	if (_me == 0) _me = new Logger();
	return _me;
}
void Logger::PutLine(QString tag, QString msg){
	mutex.lock();
	LoggerMessage lmsg(tag,msg);
	msges.enqueue(lmsg);
	mutex.unlock();
	if (!isRunning())
		start();
	//_file.open(QIODevice::Append);
	//_file.write(tag.append(":").append(msg).append("\r\n").toUtf8());
	//_file.close();
//	_file.write("HAY");
}
void Logger::SetFileName(QString file_name){
	_file_name = file_name;
}
void Logger::Kill(){
	if (_me == 0) return;
	delete _me;
	_me = 0;
}
void Logger::run(){
	_file.open(QIODevice::Append);
	LoggerMessage msg;
	forever {
		mutex.lock();
		if (msges.isEmpty())
			break;
		msg = msges.dequeue();
		if (msges.size()>1000)msges.clear();
		mutex.unlock();
		_file.write(msg.GetTag().append(": ").append(msg.GetMsg()).append("\r\n").toUtf8());

	}
	mutex.unlock();
	_file.close();

}

Logger::~Logger() {
	// TODO Auto-generated destructor stub
	//_file.close();
}
