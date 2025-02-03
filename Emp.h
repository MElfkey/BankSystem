#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Client.h"

using namespace std;

class Emp : public Person {
protected:
    double salary;

public:
    Emp() : Person(){
        this->salary = 5000;
    }

    Emp(string name, string pass, double salary) : Person(name,pass) {
        setSalary(salary);
    }

    void setSalary(double salary) {
        if (salary >= 5000)
            this->salary = salary;
        else
            cout << "Minimum salary must be at least 5000.\n";
    }

    double getSalary() { 
        return salary; 
    }

    void addClient(Client& client, string name, string pass) {
        cout << "Enter Client Name: \n";
        getline(cin, name);
        client.setName(name);
        cout << "Enter Client Password: \n";
        getline(cin, pass);
        client.setPass(pass);
        cout << "mr " << client.getName() << " added succefully .\n";
    }

    void searchClient(Client clients[], int size, int searchID) {
        for (int i = 0; i < size; i++) {
            if (clients[i].getID() == searchID) {
                cout << "Client found: " << clients[i].getName() << ", Balance: " << clients[i].getBalance() << endl;
                return;
            }
        }
        cout << "Client not found.\n";
    }

    void displayInfo() {
        cout << "Employee Name: " << getName() << ", ID: " << idOrg(getID()) << ", Salary: " << salary << endl;
    }
};
