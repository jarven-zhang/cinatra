#pragma once

#include "cinatra.hpp"
//#include "json.h"
#include <map>
#include <atomic>
#include <mutex>
#include <functional>

typedef std::shared_ptr<cinatra::conn_type> wscon;
typedef std::function<void(std::string)> WsServerCallback;

class WsServer
{
public:
	WsServer();
	int32_t Start(std::string ip,std::string port);
	void SetCallback(WsServerCallback cb);
	void SendMsg(std::string data);

private:
	void HandleWs(cinatra::request& req, cinatra::response& res);

	std::mutex m_mutex;
	std::map<uint64_t, wscon> m_wsconMap;
	std::atomic<uint64_t> m_nextId;
	WsServerCallback m_cb;
};

