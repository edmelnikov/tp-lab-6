#include <iostream>
#include "Company.h"

vector<Project*> Company::getProjectsVector() {
	return projects;
}

vector<Employee*> Company::getAllEmployeesVector() {
	return allEmployees;
}

void Company::addEmployeeToAllEmployees(Employee* employee) {
	allEmployees.push_back(employee);
}

void Company::addProject(string name, unsigned int budget) {
	Project* newProject = new Project(name, budget);
	projects.push_back(newProject);
}

void Company::payday() {
	for (int i = 0; i < allEmployees.size(); i++) {
		allEmployees[i]->calculateSalary();
	}
}

void Company::showAll() {
	cout << "-----Information about all employees in Mera-----" << endl;
	for (int i = 0; i < allEmployees.size(); i++) {
		if (allEmployees[i]->getPosition() == "Cleaner" || allEmployees[i]->getPosition() == "Driver") {
			cout << allEmployees[i]->getId() << " " << allEmployees[i]->getName() << " (" << allEmployees[i]->getPosition() << ") has worked for ";
			cout << allEmployees[i]->getWorkTime() << " hours this month and earned ";
			cout << allEmployees[i]->getPayment() << " rubles" << endl;
		}
		else if (allEmployees[i]->getPosition() == "Programmer" || allEmployees[i]->getPosition() == "Tester" || allEmployees[i]->getPosition() == "TeamLeader") {
			cout << allEmployees[i]->getId() << " " << allEmployees[i]->getName() << " (" << allEmployees[i]->getPosition() << " in " << allEmployees[i]->getProject_pointer()->getName();
			cout<< ") has worked for ";
			cout << allEmployees[i]->getWorkTime() << " hours this month and earned ";
			cout << allEmployees[i]->getPayment() << " rubles" << endl;
		}
		else if (allEmployees[i]->getPosition() == "ProjectManager") {
			cout << allEmployees[i]->getId() << " " << allEmployees[i]->getName() << " (" << allEmployees[i]->getPosition() << " in " << allEmployees[i]->getProject_pointer()->getName();
			cout << ") has earned " << allEmployees[i]->getPayment() << " rubles this month" << endl;
		}
		else if (allEmployees[i]->getPosition() == "SeniorManager") {
			cout << allEmployees[i]->getId() << " " << allEmployees[i]->getName() << " (" << allEmployees[i]->getPosition();
			cout << ") has earned " << allEmployees[i]->getPayment() << " rubles this month" << endl;
		}
	}

}