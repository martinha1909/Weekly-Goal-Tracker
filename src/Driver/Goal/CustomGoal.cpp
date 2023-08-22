#include "include/CustomGoal.h"

CustomGoal::CustomGoal(const char* name, const int id) : Goal(name, id)
{
	this->total = 0;
	this->progress = 0;
	sub_title = "";
}

CustomGoal::CustomGoal(const char* name, const int id, const int total, std::string title) : Goal(name, id)
{
	this->total = total;
	this->progress = 0;
	this->sub_title = title;
}

CustomGoal::CustomGoal(const char* name, const int id, const int total) : Goal(name, id)
{
	this->total = total;
	this->progress = 0;
	sub_title = "";
}

CustomGoal::~CustomGoal()
{
	for (size_t i = 0; i < sub_goals.size(); i++) {
		if (sub_goals[i] != nullptr) {
			delete sub_goals[i];
			sub_goals[i] = nullptr;
		}
	}
}

void CustomGoal::addSubGoal(Goal* goal)
{
	if (dynamic_cast<CustomGoal*>(goal) != nullptr) {
		CustomGoal* new_goal = dynamic_cast<CustomGoal*>(goal);
		sub_goals.push_back(new_goal);
	}
}

std::string& CustomGoal::getSubTitle()
{
	return sub_title;
}

int CustomGoal::getTotalGoal()
{
	return total;
}

int CustomGoal::getProgress()
{
	return progress;
}

int CustomGoal::getNumSubGoalsDone()
{
	return num_sub_goals_done;
}

void CustomGoal::setNumSubGoalsDone(int num_done)
{
	num_sub_goals_done = num_done;
}

void CustomGoal::setTotalGoal(int new_total)
{
	this->total = new_total;
}

void CustomGoal::setProgress(int new_progress)
{
	this->progress = new_progress;
}

std::vector<Goal*>* CustomGoal::getSubGoals()
{
	return &sub_goals;
}