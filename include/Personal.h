#pragma once

#include "Employee.h"
#include "WorkTimeInterface.h"
#include "Project.h"

class Personal : public Employee, public IWorkTime {
protected:
	unsigned int hourly_rate;
public:
	Personal(unsigned int id, string name, string position, unsigned int hourly_rate);
	unsigned int getHourly_rate();
	virtual unsigned int PaymentForHours() override;
	virtual void calculateSalary() override;
	void setProject_pointer(Project* project) override;
	virtual Project* getProject_pointer() override;
};

class Cleaner : public Personal {
public:
	Cleaner(unsigned int id, string name, unsigned int hourly_rate);
};

class Driver : public Personal {
public:
	Driver(unsigned int id, string name, unsigned int hourly_rate);
};
