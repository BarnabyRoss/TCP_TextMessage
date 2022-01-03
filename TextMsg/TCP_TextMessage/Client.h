#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <QObject>
#include <QTcpSocket>

class Client : public QObject{

  Q_OBJECT
public:
  explicit Client(QObject *parent = nullptr);

  void connectTo(QString ip, qint64 port);
  qint64 send(const char* data, int len);
  qint64 available();
  void close();

protected slots:
  void onConnected();
  void onReadyRead();
  void onBytesWritten(qint64 bytes);
  void onDisconnected();

private:
  QTcpSocket m_client;

};

#endif // __CLIENT_H__
