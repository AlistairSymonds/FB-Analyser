#pragma once
#include <vector>
#include "Message.h"
using namespace std;
class Conversation
{
public:
	Conversation(vector <string> participantsIn);
	int addMessage(Message msg);
	~Conversation();
private:
	vector<string> participants;
	vector<Message> messages;
};

