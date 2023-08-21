#pragma once

#include "Goal.h"

class DefaultGoal : public Goal
{
private:
	int num_sub_goals_done;
	std::vector<DefaultGoal*> sub_goals;
public:
	DefaultGoal(const char* name, const int id);
	~DefaultGoal();
	void addSubGoal(Goal* goal) override;
	void setNumSubGoalsDone(int num_done) override;
	int getNumSubGoalsDone();
	std::vector<DefaultGoal*>* getSubGoals();
};

