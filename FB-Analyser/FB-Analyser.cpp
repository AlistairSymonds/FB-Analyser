// FB-Analyser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

int main(int argc, char** argv)
{
	
	//get fb path
	if (argc != 2) {
		cout << "Please specify base fb directory only";
		return 1;
	}
	string fbDir = argv[1];

	stringstream ss;
	ss << argv[1] << "\\messages";
	string msgDir = ss.str();

	//setup conversation data store
	//iterate through messages directory for html files and add to queue
	
	for (auto & p : fs::directory_iterator(msgDir)) {
		if (fs::path(p).extension() == ".html") {
			cout << p << '\n';
		}
	}
		


	//process each html file into a conversation object
	//add conversation to conversation store
	//do analysis



	cin.get();


    return 0;
}

