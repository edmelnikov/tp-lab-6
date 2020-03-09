#pragma once
#include <string>
using namespace std;
class Project; //also part of the crutch

class Employee {
protected:
	unsigned int id; 
	string name;
	string position;
	unsigned int worktime = 0;
	unsigned int payment = 0;
public:
	Employee(unsigned int, string name, string position);

	unsigned int getId();
	string getName();
	string getPosition();
	unsigned int getWorkTime();
	unsigned int getPayment();
	void setWorktime(unsigned int worktime);
	virtual void calculateSalary() = 0; //calculcates and gives the salary
	virtual void setProject_pointer(Project* project) = 0; // Who's that? That's a crutch! (Most likely).
	virtual Project* getProject_pointer() = 0;
	//Well, actually it is used to set project_pointer for Engineers and managers later
};
