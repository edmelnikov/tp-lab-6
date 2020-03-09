#pragma once
#include <vector>
//#include "Employee.h"
#include "Project.h"

class Company {
private:
	vector<Project*> projects;
	vector<Employee*> allEmployees;
public:
	vector<Project*> getProjectsVector();
	vector<Employee*> getAllEmployeesVector();
	void addEmployeeToAllEmployees(Employee* employee);
	void addProject(string name, unsigned int budget);
	void payday();
	void showAll();
};