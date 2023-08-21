#pragma once

#include <string>
#include <vector>

class Goal
{
private:
	std::string name;
	int id;
	int num_sub_goals_done;
	bool completed;
	std::vector<Goal*> sub_goals;

public:
	Goal();
	Goal(const char* name, const int id);
	Goal(const char* name);
	~Goal();
	void setName(const std::string& name);
	void setID(const int id);
	int getID();
	void addSubGoal(Goal* goal);
	void setNumSubGoalsDone(int num_done);
	void setComplete(bool is_completed);
	std::string getName();
	std::vector<Goal*>* getSubGoals();
	bool isCompleted();
	int getNumSubGoalsDone();
};