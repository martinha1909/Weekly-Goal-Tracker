#include "include/Goal.h"

Goal::Goal()
{
	name = "";
}

Goal::Goal(const char* name)
{
	this->name = name;
}

Goal::Goal(const char* name, const int id)
{
	this->name = name;
	this->id = id;
}

Goal::~Goal()
{

}

void Goal::setName(const std::string& name)
{
	this->name = name;
}

void Goal::setID(const int id)
{
	this->id = id;
}

std::string Goal::getName()
{
	return name;
}

int Goal::getID()
{
	return id;
}