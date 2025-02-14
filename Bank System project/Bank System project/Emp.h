
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Client.h"

using namespace std;

class Emp : public Person {
protected:
    double salary;
    vector<Client> clients;

public:
    Emp() : Person() {
        this->salary = 5000;
    }

    Emp(string name, string pass, double salary, int id) : Person(name, pass, id) {
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


    void addClient(Client& client) {
        cout << "Enter Client Name: \n";
        getline(cin, name);
        client.setName(name);
        cout << "Enter Client Password: \n";
        getline(cin, pass);
        client.setPass(pass);
        clients.push_back(client); 
        cout << "Mr. " << client.getName() << " added successfully.\n";
    }

    Client* searchClient(int id) {
        for (auto& c : clients) {
            if (c.getID() == id) {
                return &c;
            }
        }
        return nullptr;
    }

    void listClient() {
        for (auto& c : clients) {
            c.displayInfo();
        }
    }

    void editClient(int id, double balance) {
        Client* c = searchClient(id);
        if (c != nullptr) {
            cout << "Enter the new name : \n";
            getline(cin, name);
            c->setName(name);
            cout << "Enter the new password : \n";
            getline(cin, pass);
            c->setPass(pass);
            cout << "Enter the Balance : \n";
            cin >> balance;
            c->setBalance(balance);
        }
    }

    void displayInfo() {
        cout << "Employee Name: " << getName() << ", ID: " << idOrg(getID()) << ", Salary: " << salary << endl;
    }

    ~Emp() {}
};