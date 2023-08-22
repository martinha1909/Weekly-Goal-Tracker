#include "include/DefaultGoal.h"

DefaultGoal::DefaultGoal(const char* name, const int id) : Goal(name, id)
{
	num_sub_goals_done = 0;
}
DefaultGoal::~DefaultGoal()
{
	for (size_t i = 0; i < sub_goals.size(); i++) {
		if (sub_goals[i] != nullptr) {
			delete sub_goals[i];
			sub_goals[i] = nullptr;
		}
	}
}
void DefaultGoal::addSubGoal(Goal* goal)
{
	if (dynamic_cast<DefaultGoal*>(goal) != nullptr) {
		sub_goals.push_back(dynamic_cast<DefaultGoal*>(goal));
	}
}
void DefaultGoal::setNumSubGoalsDone(int num_done)
{
	num_sub_goals_done = num_done;
}
int DefaultGoal::getNumSubGoalsDone()
{
	return num_sub_goals_done;
}

std::vector<Goal*>* DefaultGoal::getSubGoals()
{
	return &sub_goals;
}