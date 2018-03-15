#include "stdafx.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <sstream>
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
	string token;
	ifs.open(msgPath);
	vector<string> participants;
	string title = readInTag("<title>");
	readInTag("<h3>");
	//up to participants now
	
	{
		stringstream ss;
		ifs >> token;
		ifs >> token;
		while (token.find("<") == string::npos) {
			ss << token << ' ';
			ifs >> token;
		}
		ss.str();
	}
	conv = new Conversation(participants);


	ifs.close();
	return 1;
}





Conversation* FbHtmlParser::getConversation()
{
	return conv;
}

FbHtmlParser::~FbHtmlParser()
{
	
}

string FbHtmlParser::readInTag(string htmlTag)
{
	string closeTag = htmlTag;
	closeTag.insert(1, "/");	
	
	char token;
	stringstream data;
	int tagFound = 0;
	while (!tagFound) {
		token = ifs.get();
		
		for (int i = 0; i < htmlTag.size(); i++) {
			if (token != htmlTag[i]) {
				tagFound = 0;
				break;
			}
			else
			{
				tagFound = 1;
			}
			token = ifs.get();
		}


		if (ifs.eof()) {
			return htmlTag;
		}
	}
	data << token;
	tagFound = 0;
	while (!tagFound) {
		token = ifs.get();
		data << token;
		
		for (int i = 0; i < closeTag.size(); i++) {
			if (token != closeTag[i]) {
				tagFound = 0;
				break;
			}
			else
			{
				tagFound = 1;
			}
			token = ifs.get();
		}
		

		if (ifs.eof()) {
			return htmlTag;
		}
	}
	ifs.unget();
	string retVal = data.str();
	
	return retVal.substr(0, retVal.size() - 1);
}
