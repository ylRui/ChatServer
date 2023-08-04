#ifndef FRIENDMODEL_H
#define FRIENDMODEL_H

#include "user.hpp"
#include <vector>
using namespace std;

//维护好友信息的操作接口方法
class FriendModel{
public:
//添加好友关系
    void insert(int userid, int friendid);
//返回好友列表信息，姓名，在线状态等
    vector<User> query(int userid);

};



#endif