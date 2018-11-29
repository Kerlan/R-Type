/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Client main
*/

#include <boost/asio.hpp>
#include "Network/UDPClient.hpp"

int main(int ac, char **av)
{
	boost::asio::io_service ios;
	boost::asio::ip::udp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1488);
	UDPClient client(ios, 1234);

	client.send({"Hitler\n", 0, 0}, endpoint);
	ios.run();
	return 0;
}