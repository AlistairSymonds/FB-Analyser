#pragma once
#include <filesystem>
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
	fs::path msgPath;
	Conversation *conv;

};

