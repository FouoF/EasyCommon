#include<muduo/net/TcpServer.h>

class MatchServer
{
private:
    muduo::net::TcpServer _Server;

    void onConnection(const muduo::net::TcpConnectionPtr&);

    void onMessage(const muduo::net::TcpConnectionPtr&, muduo::net::Buffer*,
    muduo::Timestamp);

public:
    MatchServer(muduo::net::EventLoop*,
    const muduo::net::InetAddress&);

    void start();
};