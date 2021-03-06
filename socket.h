#ifndef SOCKET_H
#define SOCKET_H

#define SOCKET_HAS_CHINESE 1
#define SOCKET_METHOD_ONE 1

#include <QWidget>
#include <QUdpSocket>
#include <QTextCodec>
#include <QNetworkDatagram>

class TestSocket:public QWidget{
    Q_OBJECT

public:
    TestSocket(QWidget* parent = nullptr);
    ~TestSocket();

    void udp_send_data(QString sen_data, const QHostAddress &host, quint16 port);
    void udp_receive_data(const QHostAddress &host, quint16 port);

private:
    QUdpSocket* sen_qus;
    QUdpSocket* rec_qus;
    QNetworkDatagram datagram;
};

#endif // SOCKET_H
