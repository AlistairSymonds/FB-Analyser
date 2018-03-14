#include "stdafx.h"
#include <filesystem>
#include <fstream>
#include "FbHtmlParser.h"
#include "Conversation.h"

using namespace std;
namespace fs = std::experimental::filesystem;

FbHtmlParser::FbHtmlParser(fs::path msgPathIn)
{
	msgPath = msgPathIn;
}

int FbHtmlParser::parse()
{
	ifstream ifs;
	ifs.open(msgPath);
	vector<string> participants;
	participants.push_back("Tom");
	conv = new Conversation(participants);
	return 1;
}




Conversation* FbHtmlParser::getConversation()
{
	return conv;
}

FbHtmlParser::~FbHtmlParser()
{
}
