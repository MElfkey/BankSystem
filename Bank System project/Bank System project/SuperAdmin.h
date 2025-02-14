#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Person.h"
#include "Emp.h"
#include "Client.h"
#include "Admin.h"
class SuperAdmin : public Admin
{
	vector<Client> clients;
	vector<Emp> emps;
	vector<Admin> admins;

public:

	SuperAdmin(string name, string pass, double salary, int id) : Admin(name, pass, salary, id) {
	
	}
	SuperAdmin() {
	
	}


    void addAdmin(Admin& admin) {
        cout << "Enter Admin Name: \n";
        std::cin >> std::ws;
        getline(cin, name);
        admin.setName(name);
        cout << "Enter Admin Password: \n";
        getline(cin, pass);
        admin.setPass(pass);
        cout << "Enter Admin Salary:  \n";
        double salary;
        cin >> salary;
        admin.setSalary(salary);

        cout << "mr " << admin.getName() << " added successfully.\n";
    }



};

