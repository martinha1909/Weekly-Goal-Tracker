#pragma once

#include <string>
#include <vector>

class Goal
{
protected:
	std::string name;
	int id;
	bool completed;

public:
	Goal();
	Goal(const char* name, const int id);
	virtual ~Goal();
	void setName(const std::string& name);
	void setID(const int id);
	int getID();
	std::string getName();
	bool isCompleted();
	virtual void addSubGoal(Goal* goal) = 0;
	virtual void setNumSubGoalsDone(int num_done) = 0;
	void setComplete(bool is_completed);
};