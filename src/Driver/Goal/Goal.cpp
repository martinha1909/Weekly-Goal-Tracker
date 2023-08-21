#include "include/Goal.h"

Goal::Goal()
{
	name = "";
}

Goal::Goal(const char* name, const int id)
{
	this->name = name;
	this->id = id;
	completed = false;
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

void Goal::setComplete(bool is_completed)
{
	completed = is_completed;
}

bool Goal::isCompleted()
{
	return completed;
}