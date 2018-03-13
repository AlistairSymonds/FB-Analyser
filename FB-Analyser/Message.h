#pragma once
#include <string>
#include <ctime>
using namespace std;
class Message
{
public:
	Message(string senderIn, string textIn, time_t sendTimeIn);
	~Message();
private: 
	string sender;
	string text;
	time_t sendTime;
};

