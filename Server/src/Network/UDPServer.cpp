/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#include <iostream>
#include "Network/UDPServer.hpp"

UDPServer::UDPServer(boost::asio::io_service &ioService, unsigned short port, std::shared_ptr<SafeQueue<struct UDPClientStreamBufferData>> QClass)
	: _socket(ioService, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)),
	_actionQueue(QClass)
{
	this->read();
}

void UDPServer::send(struct UDPServerStreamBufferData data, boost::asio::ip::udp::endpoint endpoint)
{
	_serverStreamBuffer.write(data);
	_socket.send_to(_serverStreamBuffer.getStreamBuffer().data(), endpoint);
	_serverStreamBuffer.getStreamBuffer().consume(1024);
}

void UDPServer::read()
{
	auto buff = _clientStreamBuffer.getStreamBuffer().prepare(512);
	_socket.async_receive_from(buff, _endpoint,
		std::bind(&UDPServer::routine, this, std::placeholders::_1, std::placeholders::_2));
}

void UDPServer::routine(const boost::system::error_code &error, std::size_t size)
{
	struct UDPClientStreamBufferData data;

	if (!error) {
		data = _clientStreamBuffer.read(size);
		_actionQueue->push(data);
		if (_components.find(data.event) != _components.end())
			(*(_components.find(data.event))->second).run(_socket, _endpoint, data);
		this->read();
	} else {
		_socket.close();
	}
}