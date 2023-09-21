#include"MatchServer.h"

#include<muduo/base/Logging.h>

using std::placeholders::_1;
using std::placeholders::_2;
using std::placeholders::_3;

MatchServer::MatchServer(muduo::net::EventLoop* loop, const muduo::net::InetAddress& Addr)
: _Server(loop, Addr, "MatchServer")
{
    _Server.setConnectionCallback(std::bind(&MatchServer::onConnection, this, _1));
    _Server.setMessageCallback(std::bind(&MatchServer::onMessage, this, _1, _2, _3));
}

void MatchServer::start(){
    _Server.start();
}

void MatchServer::onConnection(const muduo::net::TcpConnectionPtr& conn){
    LOG_INFO << _Server.name() << "-" << conn->peerAddress().toIpPort() << " -> "
           << conn->localAddress().toIpPort() << " is "
           << (conn->connected() ? "UP" : "DOWN");
}

void MatchServer::onMessage(const muduo::net::TcpConnectionPtr& conn,
                           muduo::net::Buffer* buf,
                           muduo::Timestamp time)
{ muduo::string msg(buf->retrieveAllAsString());
  LOG_INFO << conn->name() << " received " << msg.size() << " bytes, "
           << "data received at " << time.toString();
}