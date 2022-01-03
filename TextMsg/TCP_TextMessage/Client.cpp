#include "Client.h"

Client::Client(QObject* parent) : QObject{parent}{

  connect(&m_client, SIGNAL(connected()), this, SLOT(onConnected()));
  connect(&m_client, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
  connect(&m_client, SIGNAL(bytesWritten(qint64)), this, SLOT(onBytesWritten(qint64)));
  connect(&m_client, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
}

void Client::connectTo(QString ip, qint64 port){

  m_client.connectToHost(ip, port);
}

qint64 Client::send(const char* data, int len){

  return m_client.write(data, len);
}

qint64 Client::available(){

  return m_client.bytesAvailable();
}

void Client::close(){

  m_client.close();
}

void Client::onConnected(){

  qDebug() << "void Client::onConnected()";
}

void Client::onReadyRead(){

  char buf[128] = { 0 };
  int len = m_client.read(buf, sizeof(buf) - 1);
  qDebug() << "receive data bytes : " << len;
  qDebug() << "receive data content : " << buf;
}

void Client::onBytesWritten(qint64 bytes){

  qDebug() << "write bytes : " << bytes;
}

void Client::onDisconnected(){

  qDebug() << "void Client::onDisconnected()";
}
