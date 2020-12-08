#include "ChatterBoxServer.h"
#include <QMessageBox>
#include <QTcpSocket>
#include <QRegExp>

ChatterBoxServer::ChatterBoxServer(QObject *parent) : QTcpServer(parent)
{
}

void ChatterBoxServer::incomingConnection(int socketfd)
{
    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(socketfd);
    clients.insert(client);
    connect(client, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void ChatterBoxServer::readyRead()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    while(client->canReadLine())
    {
        QString line = QString::fromUtf8(client->readLine()).trimmed();
        lastdata = line;
    }
}
