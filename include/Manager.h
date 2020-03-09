#pragma once
#include "Employee.h"
#include "HeadingInterface.h"
#include "ProjectInterface.h"
#include "Project.h"

class Manager : public Employee, public IProject {
protected:
	Project* project_pointer;
	double project_bonus;
public:
	Manager(unsigned int id, string name, string position, double project_bonus);
	Project* getProject_pointer();
	unsigned int getProject_bonus();
	virtual void setProject_pointer(Project* project) override;
	virtual double PaymentForProject() override;
	virtual void calculateSalary() override;
};

class ProjectManager : public Manager, public IHeading {
protected:
	unsigned int subordinates = 0;
	unsigned int payment_per_subordinate = 0;
public:
	ProjectManager(unsigned int id, string name, double project_bonus, unsigned int payment_per_subordinate);
	void setSubordinates(unsigned int subordinates);
	virtual double PaymentForHeading() override;
	virtual void calculateSalary() override;
};

class SeniorManager : public ProjectManager {
protected:
	vector<Project*> projects;
public:
	SeniorManager(unsigned int id, string name, double project_bonus, unsigned int payment_per_subordinate);
	virtual void setProject_pointer(Project* project) override; //another crutch used to get the overall budget of a company
	virtual double PaymentForProject() override;
};