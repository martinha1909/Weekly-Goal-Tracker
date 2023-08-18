#pragma once

#include <string>

class Goal
{
private:
	std::string name;
	int id;

public:
	Goal();
	Goal(const char* name, const int id);
	Goal(const char* name);
	~Goal();
	void setName(const std::string& name);
	void setID(const int id);
	std::string getName();
};