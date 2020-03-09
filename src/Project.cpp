#include "Project.h"

Project::Project(string name, unsigned int budget) {
	this->name = name;
	this->budget = budget;
}

string Project::getName() {
	return name;
}

unsigned int Project::getBudget() {
	return budget;
}

void Project::addEmployeeToProj(Employee* employee) {
	employees_in_project.push_back(employee);
}