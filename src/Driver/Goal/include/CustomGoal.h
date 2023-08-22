#pragma once

#include <string>
#include "Goal.h"

class CustomGoal : public Goal
{
private:
	int total;
	int progress;
	std::string sub_title;
public:
	CustomGoal(const char* name, const int id);
	CustomGoal(const char* name, const int id, const int total);
	CustomGoal(const char* name, const int id, const int total, std::string title);
	~CustomGoal();
	std::string& getSubTitle();
	int getTotalGoal();
	int getProgress();
	int getNumSubGoalsDone() override;
	std::vector<Goal*>* getSubGoals() override;
	void addSubGoal(Goal* goal) override;
	void setNumSubGoalsDone(int num_done) override;
	void setTotalGoal(int new_total);
	void setProgress(int new_progress);
};

