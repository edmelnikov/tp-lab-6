#include "Employee.h"


Employee::Employee(unsigned int id, string name, string position) 
	: id(id), name(name), position(position) {
}

unsigned int Employee::getId() {
	return id;
}

string Employee::getName() {
	return name;
}

string Employee::getPosition() {
	return position;
}

unsigned int Employee::getWorkTime() {
	return worktime;
}

unsigned int Employee::getPayment() {
	return payment;
}

void Employee::setWorktime(unsigned int worktime) {
	this->worktime = worktime;
}