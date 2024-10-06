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
	// The buffer for performing reads.���յ�����8k
	beast::flat_buffer  _buffer{ 8192 };
	// The request message.���նԷ�����
	http::request<http::dynamic_body> _request;
	// The response message.�ظ��Է�
	http::response<http::dynamic_body> _response;
	//��ʱ�� 60s��ʱ
	// The timer for putting a deadline on connection processing.
	net::steady_timer deadline_{
		_socket.get_executor(), std::chrono::seconds(60) };

	std::string _get_url;
	std::unordered_map<std::string, std::string> _get_params;
};

