#pragma once
#include"const.h"

class HttpConnection:public std::enable_shared_from_this<HttpConnection>
{
public:
	friend class LogicSystem;
	HttpConnection(tcp::socket socket);
	void Start();
private:
	void CheckDeadline();
	void WriteResponse();
	void HandleReq();
	void PreParseGetParam();
	tcp::socket  _socket;
	// The buffer for performing reads.接收的数组8k
	beast::flat_buffer  _buffer{ 8192 };
	// The request message.接收对方请求
	http::request<http::dynamic_body> _request;
	// The response message.回复对方
	http::response<http::dynamic_body> _response;
	//定时器 60s超时
	// The timer for putting a deadline on connection processing.
	net::steady_timer deadline_{
		_socket.get_executor(), std::chrono::seconds(60) };

	std::string _get_url;
	std::unordered_map<std::string, std::string> _get_params;
};

