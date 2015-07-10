#ifndef __SOCKET_H_
#define __SOCKET_H_

#ifdef __WIN32__
#define _WIN32_WINNT  0x501
#include <winsock2.h>
#include <ws2tcpip.h>

#define socketStartup() {WSADATA wsaData;\
	WSAStartup(0x202, &wsaData);\
}

#define socketCleanup()  WSACleanup()
#define socketGetError() WSAGetLastError()
#define EINPROGRESS WSAEWOULDBLOCK

#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>

#define socketStartup()
#define socketCleanup()
#define socketGetError() errno

#define INVALID_SOCKET	-1
#define SOCKET_ERROR	-1
#endif

#endif /*__SOCKET_H_*/
