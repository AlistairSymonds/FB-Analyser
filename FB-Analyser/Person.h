#pragma once
#include <string>
using namespace std;
class Person
{
public:
	Person(string firstName, string lastName);
	string getFirstName();
	string getLastName();
	~Person();
private:
	string _firstName;
	string _lastName;


};

