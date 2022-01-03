#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <QObject>

class Client : public QObject{

  Q_OBJECT
public:
  explicit Client(QObject *parent = nullptr);

signals:

};

#endif // __CLIENT_H__
