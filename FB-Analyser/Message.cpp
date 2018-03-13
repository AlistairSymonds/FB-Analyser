#include "stdafx.h"
#include "Message.h"


Message::Message()
{
}


Message::Message(string senderIn, string textIn, time_t sendTimeIn)
{
	this->sender = senderIn;
	this->text = textIn;
	this->sendTime = sendTimeIn;
}

Message::~Message()
{
}
