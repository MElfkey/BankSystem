#include "Person.h"
#include "Emp.h"
#include "Client.h"
#include "Admin.h"
#include "FilesHelper.h"
#include"Parser.h"
#include"FileManger.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



static Client* validUser(int id, string pass) {
	for (auto& c : allClients) {
		if (c.getID() == id && c.getPass() == pass) {
			return &c;
		}
	}
	return nullptr;
}

static Client* validUser(int id) {
	for (auto& c : allClients) {
		if (c.getID() == id) {
			return &c;
		}
	}
	return nullptr;
}

static void updatePass(Person* p) {
	string pass;
	cout << "Enter your new password: ";
	getline(cin, pass);
	p->setPass(pass);
}

static void displayMessage() {
	cout << "Welcome to our Bank System, " << "!\n";
	cout << "We have an excellent team ready to assist you at any time!!." << endl;
	cout << "We provide 24/7 and hope our service meets your satisfaction and approval." << endl;
	cout << endl;
}

void login (){
	int n;
	cout << "if you are an employee enter 1 \n" << " if you are Client  enter 2 .\n" << endl;
	cout << "if you are an Admin enter 3 \n";
	cin >> n;
	if (n == 1) {
		Emp e;
		cout << "Enter your ID : \n";
		int id;
		cin >> id;
		e.setId(id);
		cout << "Enter the Password : \n";
		string pass;
		e.setPass(pass);
		if (validUser(e.getID(), e.getPass()) != nullptr) {
			int n;
			cout << "Welcome Mr " << e.getName() << ", lets go to start our tasks . \n";

			cout << "1: Add new Client \n";
			cout << "2: Search for Client \n";
			cout << "3: Edit Client \n";
			cout << "4: Delete Client \n";
			cout << "5: Display all Clients \n";
			cout << "6: Change password \n";
			cout << "7: Exit\n";
			cin >> n;
			if (n == 1) {
				Client c;
				e.addClient(c);
			}
			else if (n == 2) {
				int id;
				cout << "Enter the ID of the client you want to search for : \n";
				cin >> id;
				e.searchClient(id);
			}
			else if (n == 3) {
				int id;
				double balance;
				cout << "Enter the ID of the client you want to edit : \n";
				cin >> id;
				cout << "Enter the new balance : \n";
				cin >> balance;
				e.editClient(id, balance);
			}
			else if (n == 4) {
				int id;
				cout << "Enter the ID of the client you want to delete : \n";
				cin >> id;
				e.deleteClient(id);

			}
			else if (n == 5) {
				e.listClient();
			}

			else if (n == 6) {
				updatePass(&e);
			}
			else if (n == 7) {
				return;

			}
		}
		else if (n == 2) {
			Client c;
			cout << "Enter the ID : \n";
			int id;
			cin >> id;
			c.setId(id);
			cout << "Enter the Password : \n";
			string pass;
			c.setPass(pass);
			if (validUser(c.getID(), c.getPass()) != nullptr) {
				int n;
				cout << "Welcome Mr " << c.getName() << ", Tell us how we can help you\n";
				cout << "1: Deposit\n";
				cout << "2: Withdraw\n";
				cout << "3: Transfer\n";
				cout << "4: Change password\n";
				cout << "5: Check balance\n";
				cout << "6: Display all information\n";
				cout << "7: Exit\n";
				cin >> n;
				if (n == 1) {
					c.deposit();
				}
				else if (n == 2) {
					c.withdraw();
				}
				else if (n == 3) {
					Client tmp;
					int id;
					cin >> id;
					if (validUser(id) != nullptr) {
						tmp = *validUser(id);
						c.transferTo(tmp);

					}
					else {
						cout << "The user not found \n";
					}
				}
				else if (n == 4) {
					updatePass(&c);
				}
				else if (n == 5) {
					c.CheckBalance();
				}
				else if (n == 6) {
					c.displayInfo();
				}
				else if (n == 7) {
					return;
				}
			}
			else {
				return;
			}
		}
		else if (n == 3) {
			Admin a;
			cout << "Enter your ID : \n";
			int id;
			cin >> id;
			a.setId(id);
			cout << "Enter the Password : \n";
			string pass;
			a.setPass(pass);
			if (validUser(a.getID(), a.getPass()) != nullptr) {
				int n;
				cout << "Welcome Mr " << a.getName() << ", lets go to start our tasks . \n";
				cout << "1: Add new Employee \n";
				cout << "2: Search for Employee \n";
				cout << "3: Edit Employee \n";
				cout << "4: Delete Employee \n";
				cout << "5: Display all Employees \n";
				cout << "6: Change password \n";
				cout << "7: Add new Client\n";
				cout << "8: Delete Client \n";
				cout << "9: Display all Clients \n";
				cout << "10: Update Client\n";
				cout << "11: Exit\n";
				cin >> n;
				if (n == 1) {
					Emp e;
					a.addEmp(e);
				}
				else if (n == 2) {
					int id;
					cout << "Enter the ID of the Employee you want to search for : \n";
					cin >> id;
					a.searchEmp(id);
				}
				else if (n == 3) {
					int id;
					double salary;
					cout << "Enter the ID of the Employee you want to edit : \n";
					cin >> id;
					cout << "Enter the new salary : \n";
					cin >> salary;
					a.editEmp(id, salary);
				}
				else if (n == 4) {
					int id;
					cout << "Enter the ID of the Employee you want to delete : \n";
					cin >> id;
					a.deleteEmp(id);
				}
				else if (n == 5) {
					a.listEmp();
				}
				else if (n == 6) {
					updatePass(&a);
				}
				else if (n == 7) {
					Client c;
					a.addClient(c);
				}
				else if (n == 8) {
					int id;
					cout << "Enter the ID of the client you want to delete : \n";
					cin >> id;
					a.deleteClient(id);
				}
				else if (n == 9) {
					a.listClient();
				}
				else if (n == 10) {
					int id;
					double balance;
					cout << "Enter the ID of the client you want to edit : \n";
					cin >> id;
					cout << "Enter the new balance : \n";
					cin >> balance;
					a.editClient(id, balance);
				}
				else if (n == 11) {
					return;
				}
			}
			else {
				return;
			}

		}
		else {
			cout << "Invalid input please try again .\n";
			cin >> n;
		}
	}

	int main() {
		FilesHelper::getClients();
		FilesHelper::getEmployees();
		FilesHelper::getAdmins();
		displayMessage();
		login();
		return 0;
	}