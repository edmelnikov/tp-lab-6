#include "gtest/gtest.h"
#include "Company.h"
#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"
#include "Project.h"

TEST(lab6, task1) {
	Cleaner worker = Cleaner(1, "Alex", 100);
	worker.setWorktime(160);
	worker.calculateSalary();
	unsigned int salary = worker.getPayment();
	EXPECT_EQ(salary, 16000);
}

TEST(lab6, task2) {
	Project* project1 = new Project("project1", 50000);
	Programmer worker = Programmer(0, "Alex", 150, 0.2);
	worker.setProject_pointer(project1);
	worker.setWorktime(160);
	worker.calculateSalary();
	unsigned int salary = worker.getPayment();
	EXPECT_EQ(salary, 34000);
}

TEST(lab6, task3) {
	Project* project1 = new Project("project1", 50000);
	TeamLeader worker = TeamLeader(0, "Alex", 150, 0.2, 1000);
	worker.setWorktime(180);
	worker.setSubordinates(5);
	worker.setProject_pointer(project1);
	worker.calculateSalary();
	unsigned int salary = worker.getPayment();
	EXPECT_EQ(salary, 42000);
}

TEST(lab6, task4) {
	Project* project1 = new Project("project1", 50000);
	Project* project2 = new Project("project2", 70000);
	SeniorManager worker = SeniorManager(0, "Alex", 0.2, 1000);
	worker.setProject_pointer(project1);
	worker.setProject_pointer(project2);
	worker.setSubordinates(4);
	worker.calculateSalary();
	unsigned int salary = worker.getPayment();
	EXPECT_EQ(salary, 28000);
}