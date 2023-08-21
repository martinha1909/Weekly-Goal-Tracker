#include "include/Goal.h"

Goal::Goal()
{
	name = "";
}

Goal::Goal(const char* name)
{
	this->name = name;
	completed = false;
	num_sub_goals_done = 0;
}

Goal::Goal(const char* name, const int id)
{
	num_sub_goals_done = 0;
	this->name = name;
	this->id = id;
	completed = false;
}

Goal::~Goal()
{
	for (size_t i = 0; i < sub_goals.size(); i++) {
		if (sub_goals[i] != nullptr) {
			delete sub_goals[i];
			sub_goals[i] = nullptr;
		}
	}
}

void Goal::addSubGoal(Goal* goal)
{
	sub_goals.push_back(goal);
}

void Goal::setName(const std::string& name)
{
	this->name = name;
}

void Goal::setNumSubGoalsDone(int num_done)
{
	num_sub_goals_done = num_done;
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

std::vector<Goal*>* Goal::getSubGoals()
{
	return &sub_goals;
}

void Goal::setComplete(bool is_completed)
{
	completed = is_completed;
}

bool Goal::isCompleted()
{
	return completed;
}

int Goal::getNumSubGoalsDone()
{
	return num_sub_goals_done;
}