#pragma once
#include "Employee.h"
#include "WorkTimeInterface.h"
#include "ProjectInterface.h"
#include "HeadingInterface.h"
#include "Project.h"

class Engineer : public Employee, public IWorkTime, public IProject {
protected:
	unsigned int hourly_rate;
	Project* project_pointer = NULL;
	double project_bonus; 
public:
	Engineer(unsigned int id, string name, string position, unsigned int hourly_rate, double project_bonus);
	unsigned int getHourly_rate();
	//Project* getProject_pointer();
	double getProject_bonus();
	void setProject_pointer(Project* project) override;
	virtual Project* getProject_pointer() override;
	virtual unsigned int PaymentForHours() override;
	virtual double PaymentForProject() override;
	virtual void calculateSalary() override;
};

class Programmer : public Engineer {
public:
	Programmer(unsigned int id, string name, unsigned int hourly_rate, double project_bonus);
};

class Tester : public Engineer {
public:
	Tester(unsigned int id, string name, unsigned int hourly_rate, double project_bonus);
};

class TeamLeader : public Engineer, public IHeading {
protected:
	unsigned int subordinates = 0;
	unsigned int payment_per_subordinate = 0;
public: 
	TeamLeader(unsigned int id, string name, unsigned int hourly_rate, double project_bonus, unsigned int payment_per_subordinate);
	void setSubordinates(unsigned int subordinates);
	virtual double PaymentForHeading() override;
	virtual void calculateSalary() override;
};