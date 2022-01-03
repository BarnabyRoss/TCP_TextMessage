#include "Client.h"

Client::Client(QObject* parent) : QObject{parent}{

}

void Client::connectTo(QString ip, qint64 port){

  m_client.connectToHost(ip, port);
}

qint64 Client::send(const char* data, int len){


}

qint64 Client::available(){


}

void Client::close(){


}

void Client::onConnected(){


}

void Client::onReadyRead(){


}

void Client::onBytesWritten(qint64 bytes){


}

void Client::onDisconnected(){


}
