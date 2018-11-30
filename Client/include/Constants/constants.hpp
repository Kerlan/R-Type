/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** constants
*/

#ifndef CONSTANTS_HPP_
	#define CONSTANTS_HPP_


namespace Constants {

    enum TcpActions {
        OK,
        KO,
        CONNECT,
        CREATE,
        LIST,
        JOIN,
        JOINED,
        READY,
        START
    };
    const std::size_t MaxPayloadSize = 1024;
}

#endif /* !CONSTANTS_HPP_ */