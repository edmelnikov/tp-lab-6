#include "Personal.h"

Personal::Personal(unsigned int id, string name, string position, unsigned int hourly_rate) 
	: Employee(id, name, position), hourly_rate(hourly_rate){
}

unsigned int Personal::PaymentForHours() {
	return worktime * hourly_rate;
}

unsigned int Personal::getHourly_rate() {
	return hourly_rate;
}

void Personal::calculateSalary() {
	payment = PaymentForHours();
}

void Personal::setProject_pointer(Project* project) { 
	//Crutch intensifies
}

Project* Personal::getProject_pointer() {
	return NULL;
}

Cleaner::Cleaner(unsigned int id, string name, unsigned int hourly_rate) 
	: Personal(id, name, "Cleaner", hourly_rate) {
}

Driver::Driver(unsigned int id, string name, unsigned int hourly_rate) 
	: Personal(id, name, "Driver", hourly_rate) {
}