#pragma once
#include <filesystem>
#include <fstream>
#include "Conversation.h"



using namespace std;
namespace fs = std::experimental::filesystem;

class FbHtmlParser
{
public:
	FbHtmlParser(fs::path msgPathIn);
	int parse();
	Conversation* getConversation();
	~FbHtmlParser();

private:
	string readInTag(string htmlTag);

	fs::path msgPath;
	Conversation *conv;
	ifstream ifs;
};

