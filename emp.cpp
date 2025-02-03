#include "emp.h"

Emp::Emp()
{
	this->salary = 5000;
}

Emp::Emp(string name, string pass, double salary) : Person(name, pass) {
	setSalary(salary);
}

void Emp::setSalary(double salary) {
	if (salary >= 5000)
		this->salary = salary;
	else
		cout << "Minimum salary must be at least 5000.\n";
}

double Emp::getSalary() { 
	return salary;
}

void Emp::addClient(Client & client)
{
	string name, pass;
	cout << "Enter Client Name: \n";
	getline(cin, name);
	client.setName(name);

	cout << "Enter Client Password: \n";
	getline(cin, pass);
	client.setPass(pass);

	cout << "Mr. " << client.getName() << " added successfully.\n";

}

void Emp::searchClient(Client clients[], int size, int searchID)
{
	for (int i = 0; i < size; i++) {
		if (clients[i].getID() == searchID) {
			cout << "Client found: " << clients[i].getName()
				<< ", Balance: " << clients[i].getBalance() << endl;
			return;
		}
	}
	cout << "Client not found.\n";
}

void Emp::displayInfo()
{
	cout << "Employee Name: " << getName() << ", ID: " << idOrg(getID())
		<< ", Salary: " << salary << endl;
}
