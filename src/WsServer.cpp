/*************************************************************************
#	> File Name:WsServer.cpp
#	> Author: jarven
#	> Mail: whuaw@aliyun.com
#	> Created Time: Tue 09 Mar 2021 11:22:06 AM CST
 ************************************************************************/
#include "WsServer.h"
#include <thread>
#include <iostream>
#include <map>
#include <unordered_map>
using namespace cinatra;
using namespace std;

/*std::thread::id tid = std::this_thread::get_id();
		printf("%s%d\n","--------------------------------",index);
		printf("%d\n",tid);*/
		//index += 1;

class Test
{
public:
	bool operator<(const Test& one)
	{
		return true;
	}
};

void WsServer::HandleWs(request& req, response& res) 
{
	if (req.get_content_type() != content_type::websocket) 
	{
		//gLog->Log("HandleWs error");
		//LogFile::GetInstance()->Log("HandleWs error");
		return;	
	}
	
	req.on(ws_open, [&](request& req) 
	{//用户连接
		std::cout << "open!thread id:" << std::this_thread::get_id() <<  std::endl;
		std::cout << "open!req addr:" << &req <<  std::endl;
		//wscon wsds_ptr = req.get_conn<cinatra::NonSSL>()->shared_from_this();
		//m_UserManag->create_user(wsds_ptr);
		
	});

	req.on(ws_message, [&](request& req) 
	{//接收消息
		std::cout << "send message!" << std::this_thread::get_id() << std::endl;
		std::cout << "open!req addr:" << &req <<  std::endl;
		req.get_conn<cinatra::NonSSL>()->shared_from_this()->send_ws_string("Hello, we received your request!");
		//wscon ws_ptr = req.get_conn<cinatra::NonSSL>()->shared_from_this();
		//echo
		auto part_data = req.get_part_data();
		std::string str = std::string(part_data.data(), part_data.length());
		req.get_conn<cinatra::NonSSL>()->shared_from_this()->send_ws_string(str);
		//std::cout << str << std::endl;
		//m_UserManag->recv_msg(ws_ptr, str);
	});

	req.on(ws_close, [&](request& req) {//连接断开
		std::cout << "open!req addr:" << &req <<  std::endl;
		std::cout << "Disconnection!" << std::this_thread::get_id() << std::endl;
		});

	req.on(ws_error, [&](request& req) {
		});
}


WsServer::WsServer()
{
	//m_UserManag = new UserManag();
	//gLog = new LogFile();
	//gLog->Log("server ");
	//LogFile::GetInstance()->Log("server");
}


int WsServer::Start(std::string ip, std::string port) 
{
#if 1
	//LogFile::GetInstance()->Log("server  start");
	http_server server(10);
	if (false == server.listen(ip, port)) {
	//	gLog->Log("服务启动失败");
	///	LogFile::GetInstance()->Log("服务启动失败");
		std::cout << "------start error----" << std::endl;
		return -1;
	}
	std::cout << "------start ----" << std::endl;
	server.enable_http_cache(false);//set global cache
	
	//index = 0;
	//auto f = std::bind(&WsServer::HandleWs, this, std::placeholders::_1, std::placeholders::_2);

	server.set_http_handler<GET, POST>("/", [&](request& req, response& res) {HandleWs(req, res);});
	server.run();
#endif
	return 0;
}
 
void WsServer::SetCallback(WsServerCallback cb)
{
	m_cb = cb;
}

