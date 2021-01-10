#pragma once
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <WS2tcpip.h>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#pragma comment (lib, "ws2_32.lib")

using namespace std;

class Device
{
public:
	Device();
	void sendFromClientSocket();
	~Device();

private:
	//Ipadress of the Socketserver
	string ipAddress = "127.0.0.1";
	//Listening port of the server
	int port = 54000;
	string deviceId, ipAdress, deviceType, deviceCategory, unit;
	int value;

	string generateDeviceId();
	string generateIpAdress();
	string generateDeviceType();
	string generateDeviceCategory();
	string generateUnit();
	string generateValue();
	void sendDevice(SOCKET clientSocket);
	void listenToServer(int sendResult, SOCKET clientSock);
}
