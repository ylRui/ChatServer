#include "chatserver.hpp"
#include "json.hpp"
#include "chatservice.hpp"
#include <functional>
#include <string>
using json = nlohmann::json;
using namespace std;
using namespace placeholders;

ChatServer::ChatServer(EventLoop* loop,
            const InetAddress& listenAddr,
            const string& nameArg)
            :_server(loop, listenAddr, nameArg), _loop(loop){
                _server.setConnectionCallback(std::bind(&ChatServer::onConnection, this, _1));
                _server.setMessageCallback(std::bind(&ChatServer::onMessage, this, _1, _2, _3));
                _server.setThreadNum(4);
            }
void ChatServer::start(){
    _server.start();
}
    //上报连接相关信息的回调函数
void ChatServer::onConnection(const TcpConnectionPtr& conn){
    //客户端断开连接
    if(!conn->connected()){
        ChatService::instance()->clientCloseException(conn);
        conn->shutdown();
    }


}
    //上报读写事件相关信息的回调函数, 从网络模块中读取某个具体业务，然后跟业务模块解耦
void ChatServer::onMessage(const TcpConnectionPtr& conn, 
                    Buffer* buffer,
                    Timestamp time){
    string buf = buffer->retrieveAllAsString();
    json js = json::parse(buf);
    //通过 js["msgid"] 获取业务 msghandler
    auto msgHandler = ChatService::instance()->getHandler(js["msgid"].get<int>());
    msgHandler(conn, js, time);
                         

}
  //  TcpServer _server;  //组合的muduo库，实现服务器功能的类对象
  //  EventLoop *_loop;   //指向事件循环对象的指针
