#include "Engineer.h"

Engineer::Engineer(unsigned int id, string name, string position, unsigned int hourly_rate, double project_bonus) 
	: Employee(id, name, position), hourly_rate(hourly_rate), project_bonus(project_bonus){
}

unsigned int Engineer::getHourly_rate() {
	return hourly_rate;
}
/*
Project* Engineer::getProject_pointer() {
	return project_pointer;
}
*/
double Engineer::getProject_bonus() {
	return project_bonus;
}

void Engineer::setProject_pointer(Project* project) {
	project_pointer = project;
}

Project* Engineer::getProject_pointer() {
	return project_pointer;
}

unsigned int Engineer::PaymentForHours() {
	return worktime * hourly_rate;
}

double Engineer::PaymentForProject() {
	return project_pointer->getBudget() * project_bonus;
}

void Engineer::calculateSalary() {
	payment = PaymentForHours() + PaymentForProject();
}

Programmer::Programmer(unsigned int id, string name, unsigned int hourly_rate, double project_bonus)
	: Engineer(id, name, "Programmer", hourly_rate, project_bonus) {
}

Tester::Tester(unsigned int id, string name, unsigned int hourly_rate, double project_bonus)
	: Engineer(id, name, "Tester", hourly_rate, project_bonus) {
}

TeamLeader::TeamLeader(unsigned int id, string name, unsigned int hourly_rate, double project_bonus, unsigned int payment_per_subordinate)
	: Engineer(id, name, "TeamLeader", hourly_rate, project_bonus), payment_per_subordinate(payment_per_subordinate){

}

void TeamLeader::setSubordinates(unsigned int subordinates) {
	this->subordinates = subordinates;
}

double TeamLeader::PaymentForHeading() {
	return subordinates * payment_per_subordinate;
}

void TeamLeader::calculateSalary() {
	payment = PaymentForHeading() + PaymentForProject() + PaymentForHours();
}