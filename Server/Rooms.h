#include<muduo/net/TcpConnection.h>
#include<unordered_map>

typedef std::pair<muduo::net::TcpConnection&, muduo::net::TcpConnection&> Room;

class Rooms
{
private:
    int AllocateRoom(muduo::net::TcpConnectionPtr&);
    static Rooms* rooms;
    std::unordered_map<int, Room> Rooms_map;
    Rooms();
public:
    static Rooms * InitRooms();
    int BuildRoom (int, muduo::net::TcpConnectionPtr&);
};

Rooms::Rooms(){}

Rooms * Rooms::InitRooms(){
    if (rooms == 0){
        rooms = new Rooms();
    }
    return rooms;
}