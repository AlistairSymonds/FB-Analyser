#include "stdafx.h"
#include "Conversation.h"


Conversation::Conversation(vector<string> participantsIn)
{

}

int Conversation::addMessage(Message msg)
{
	messages.push_back(msg);
	return 0;
}

Conversation::~Conversation()
{
}
