#pragma once
#include <string>
#include <vector>
#include "Employee.h"
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"

class Factory {
public:	
	Cleaner* createCleaner(int id, string name, unsigned int hourly_rate, unsigned int worktime);
	Driver* createDriver(int id, string name, unsigned int hourly_rate, unsigned int worktime);
	Programmer* createProgrammer(int id, string name, unsigned int hourly_rate, unsigned int worktime, double project_bonus);
	Tester* createTester(int id, string name, unsigned int hourly_rate, unsigned int worktime, double project_bonus);
	TeamLeader* createTeamLeader(unsigned int id, string name, unsigned int hourly_rate, unsigned int worktime, double project_bonus, unsigned int subordinates, unsigned int payment_per_subordinate);
	ProjectManager* createProjectManager(unsigned int id, string name, double project_bonus, unsigned int subordinates, unsigned int payment_per_subordinate);
	SeniorManager* createSeniorManager(unsigned id, string name, double project_bonus, unsigned int subordinates, unsigned int payment_per_subordinate);
	Employee* createEmployee(vector<string> input);
};