#include "stdafx.h"
#include "Person.h"

Person::Person(string firstName, string lastName)
{
	_firstName = firstName;
	_lastName = lastName;
}

string Person::getFirstName()
{
	return _firstName;
}

string Person::getLastName()
{
	return _lastName;
}

Person::~Person()
{
}
