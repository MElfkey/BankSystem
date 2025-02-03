#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Emp.h"
#include "Client.h"

using namespace std;
class Admin :public Emp
{
public:
	//Cons:
	Admin() {

	}
	Admin(string name, string pass, double salary) :Emp(name,pass,salary){

	}

	double getSalary() {
		return salary*=0.2;
	}


	void addEmp(Emp& Emp, string name, string pass,double salary) {
		cout << "Enter Employee Name: \n";
		getline(cin, name);
		Emp.setName(name);
		cout << "Enter Employee Password: \n";
		getline(cin, pass);
		Emp.setPass(pass);
		cout << "Enter Employee Salary:  \n";
		cin >> salary;
		Emp.setSalary(salary);
		cout << "mr " << Emp.getName() << " added succefully .\n";
	}

	void displayInfo() {
		cout << "Admin Name: " << getName() << ", ID: " << idOrg(getID()) << ", Salary: " << salary << endl;
	}
};