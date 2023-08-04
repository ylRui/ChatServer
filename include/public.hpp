#ifndef PUBLIC_H
#define PUBLIC_H

enum EnMsgType{
    LOGIN_MSG = 1,  //登录消息  绑定登录的id
    LOGIN_MSG_ACK,
    LOGINOUT_MSG, // 注销消息LOGINOUT_MSG, 
    REG_MSG,    //注册消息   绑定注册的id
    REG_MSG_ACK,
    ONE_CHAT_MSG,
    ADD_FRIEND_MSG,

    CREATE_GROUP_MSG,
    ADD_GROUP_MSG,
    GROUP_CHAT_MSG,
};

#endif