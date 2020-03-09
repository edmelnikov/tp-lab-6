#include <sstream>
#include <fstream>
#include <ostream>
#include <iostream>
#include <vector>

#include "Company.h"
#include "Project.h"
#include "Employee.h"
#include "Personal.h"
#include "Factory.h"
#include "StringSplitter.h"
using namespace std;

/* input file:
for personal:
<Name>|<Position>|<hourly_rate>|<worktime>|
for engineers and testers:
<Name>|<Position>|<hourly_rate>|<worktime>|<project_name>|<contribution>
for teamleaders 
<Name>|<Position>|<hourly_rate>|<worktime>|<project_name>|<contribution>|<amount of subordinates>|<payment per subordinate>
for projectmanagers 
<Name>|<Position>|<project_name>|<contribution>|<amount of subordinates>|<payment per subordinate>
for senior managers 
<Name>|<Position>|<contribution>|<amount of subordinates>|<payment per subordinate>
*/


int main() {	
	ifstream fin;
	string line;
	vector<string> data;
	Company Mera;
	Factory factory;
	fin.open("Projects.txt");
	if (fin.is_open()) {
		while (getline(fin, line)) {
			data = split(line, '|');
			Mera.addProject(data[0], stoi(data[1])); //creates vector of all projects
		}
	}
	else {
		cout << "error" << endl;
	}
	fin.close();

	vector<Project*> projects = Mera.getProjectsVector();
	Project* temp_project_pointer;
	fin.open("Employees.txt");
	if (fin.is_open()) {
		while (getline(fin, line)) {
			data = split(line, '|');
			Employee* employee = factory.createEmployee(data);
			if (employee != NULL) { //checks if the factory worked correctly
				Mera.addEmployeeToAllEmployees(employee);
				if (data[1] != "Cleaner" && data[1] != "Driver" && data[1] != "SeniorManager" && data[1] != "ProjectManager") {
					for (int i = 0; i < projects.size(); i++) {
						if (data[4] == projects[i]->getName()) {
							temp_project_pointer = projects[i]; //Finds a project pointer by name of a project
							employee->setProject_pointer(temp_project_pointer); //and sets it for the employee using the crutch function
						}
					}
				}
				else if (data[1] == "ProjectManager") {
					for (int i = 0; i < projects.size(); i++) {
						if (data[2] == projects[i]->getName()) {
							temp_project_pointer = projects[i]; //Finds a project pointer by name of a project
							employee->setProject_pointer(temp_project_pointer); //and sets it for the employee using the crutch function
						}
					}
				}
				else if (data[1] == "SeniorManager") {
					for (int i = 0; i < projects.size(); i++) {
						employee->setProject_pointer(projects[i]);
					}
				}
			}
			else {
				continue; // if not, skips the step
			}
		}

		Mera.payday();
		Mera.showAll();
	}
	else {
		cout << "error" << endl;
	}
	fin.close();

	return 0;
}
