#pragma once

#include "Goal.h"

class DefaultGoal : public Goal
{
private:
	
public:
	DefaultGoal(const char* name, const int id);
	~DefaultGoal();
	void addSubGoal(Goal* goal) override;
	void setNumSubGoalsDone(int num_done) override;
	int getNumSubGoalsDone() override;
	std::vector<Goal*>* getSubGoals() override;
};

