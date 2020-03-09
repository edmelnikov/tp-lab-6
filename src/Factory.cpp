#include <iostream>
#include "Factory.h"

unsigned int id = -1;

Cleaner* Factory::createCleaner(int id, string name, unsigned int hourly_rate, unsigned int worktime) {
	Cleaner* output_pointer = new Cleaner(id, name, hourly_rate);
	output_pointer->setWorktime(worktime);
	return output_pointer;
}

Driver* Factory::createDriver(int id, string name, unsigned int hourly_rate, unsigned int worktime) {
	Driver* output_pointer = new Driver(id, name, hourly_rate);
	output_pointer->setWorktime(worktime);
	return output_pointer;
}

Programmer* Factory::createProgrammer(int id, string name, unsigned int hourly_rate, unsigned int worktime, double project_bonus) {
	Programmer* output_pointer = new Programmer(id, name, hourly_rate, project_bonus);
	output_pointer->setWorktime(worktime);
	return output_pointer;
}

Tester* Factory::createTester(int id, string name, unsigned int hourly_rate, unsigned int worktime, double project_bonus) {
	Tester* output_pointer = new Tester(id, name, hourly_rate, project_bonus);
	output_pointer->setWorktime(worktime);
	return output_pointer;
}

TeamLeader* Factory::createTeamLeader(unsigned int id, string name, unsigned int hourly_rate, unsigned int worktime, double project_bonus, unsigned int subordinates, unsigned int payment_per_subordinate) {
	TeamLeader* output_pointer = new TeamLeader(id, name, hourly_rate, project_bonus, payment_per_subordinate);
	output_pointer->setWorktime(worktime);
	output_pointer->setSubordinates(subordinates);
	return output_pointer;
}

ProjectManager* Factory::createProjectManager(unsigned int id, string name, double project_bonus, unsigned int subordinates, unsigned int payment_per_subordinate) {
	ProjectManager* output_pointer = new ProjectManager(id, name, project_bonus, payment_per_subordinate);
	output_pointer->setSubordinates(subordinates);
	return output_pointer;
}

SeniorManager* Factory::createSeniorManager(unsigned id, string name, double project_bonus, unsigned int subordinates, unsigned int payment_per_subordinate) {
	SeniorManager* output_pointer = new SeniorManager(id, name, project_bonus, payment_per_subordinate);
	output_pointer->setSubordinates(subordinates);
	return output_pointer;
}

Employee* Factory::createEmployee(vector<string> input) {
	
	// For engineers and personal:
	// input[1] is a position for every employee
	// input[2] is hourly rate
	// input[3] is worktime 
	// input[4] is the name of a project (if present)
	// input[5] is the contribution to the project (if present)
	// input[6] is the amount of subordinates
	// input[7] is the payment per subordinate

	if (input.size() < 2) {
		cout << "Error in factory has occured! Not enough input data!" << endl;
		return NULL;
	}
	else {
		id++;
		if (input[1] == "Cleaner") { 
			return createCleaner(id, input[0], stoi(input[2]), stoi(input[3]));
		}
		else if (input[1] == "Driver") {
			return createDriver(id, input[0], stoi(input[2]), stoi(input[3]));
		}  
		else if (input[1] == "Programmer") {
			return createProgrammer(id, input[0], stoi(input[2]), stoi(input[3]), stod(input[5]));
		}
		else if (input[1] == "Tester") {
			return createTester(id, input[0], stoi(input[2]), stoi(input[3]), stod(input[5]));
		}
		else if (input[1] == "TeamLeader") {
			return createTeamLeader(id, input[0], stoi(input[2]), stoi(input[3]), stod(input[5]), stoi(input[6]), stoi(input[7]));
		}
		else if (input[1] == "ProjectManager") {
			return createProjectManager(id, input[0], stod(input[3]), stoi(input[4]), stoi(input[5]));
		}
		else if (input[1] == "SeniorManager") {
			return createSeniorManager(id, input[0], stod(input[2]), stoi(input[3]), stoi(input[4]));
		}
		else {
			cout << "Error in factory has occured! There is no such position as '" << input[1] << "'" << endl;
			return NULL;
		}
	}
}