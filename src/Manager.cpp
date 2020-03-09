#include "Manager.h"
#include <iostream>

Manager::Manager(unsigned int id, string name, string position, double project_bonus)
	:Employee(id, name, position), project_bonus(project_bonus){

}

unsigned int Manager::getProject_bonus() {
	return project_bonus;
}

Project* Manager::getProject_pointer() {
	return project_pointer;
}

void Manager::setProject_pointer(Project* project) {
	project_pointer = project;
}

double Manager::PaymentForProject() {
	return project_pointer->getBudget() * project_bonus;
}

void Manager::calculateSalary() {
	payment = PaymentForProject();
}

ProjectManager::ProjectManager(unsigned int id, string name, double project_bonus, unsigned int payment_per_subordinate) 
	: Manager(id, name, "ProjectManager", project_bonus), payment_per_subordinate(payment_per_subordinate){

}

void ProjectManager::setSubordinates(unsigned int subordinates) {
	this->subordinates = subordinates;
}

double ProjectManager::PaymentForHeading() {
	return subordinates * payment_per_subordinate;
}

void ProjectManager::calculateSalary() {
	payment = PaymentForHeading() + PaymentForProject();
}

SeniorManager::SeniorManager(unsigned int id, string name, double project_bonus, unsigned int payment_per_subordinate)
	: ProjectManager(id, name, project_bonus, payment_per_subordinate){
	position = "SeniorManager";
}

void SeniorManager::setProject_pointer(Project* project) {
	projects.push_back(project);
}

double SeniorManager::PaymentForProject() {
	double sum = 0;
	for (int i = 0; i < projects.size(); i++) {
		sum += projects[i]->getBudget() * project_bonus;
	}
	return sum;
}

