#include"Rooms.h"

#include<muduo/base/Logging.h>

int BuildRoom(int num, muduo::net::TcpConnectionPtr& conn){
    if (num == 0) 
    return AllocateRoom(conn);
    
}

int AllocateRoom(muduo::net::TcpConnectionPtr& conn){
    return 0;
}