#include "Emp.h"

int main() {
	string name, pass;
	double balance, salary;

	cout << "Enter Employee Name: ";
	getline(cin, name);

	cout << "Enter Employee Password (7 characters): ";
	getline(cin, pass);

	cout << "Enter Employee Salary (minimum 5000): ";
	cin >> salary;
	cin.ignore();  

	Emp emp(name, pass, salary);
	emp.displayInfo();

	cout << "\n--- Register New Client ---\n";
	cout << "Enter Client Name: ";
	getline(cin, name);

	cout << "Enter Client Password (7 characters): ";
	getline(cin, pass);

	cout << "Enter Initial Balance: ";
	cin >> balance;
	cin.ignore();

	Client client(name, pass, balance);
	client.displayMessage();

	int searchID;
	cout << "\nEnter Client ID to search: ";
	cin >> searchID;

	Client clients[] = { client };
	emp.searchClient(clients, 1, searchID);

	return 0;
}
