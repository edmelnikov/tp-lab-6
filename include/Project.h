#pragma once
#include <vector>
#include "Employee.h"

class Project {
private:
	string name;
	unsigned int budget;
	vector<Employee*> employees_in_project;
public:
	Project(string name, unsigned int budget);
	string getName();
	unsigned int getBudget();
	void addEmployeeToProj(Employee* employee);
};