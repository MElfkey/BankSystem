#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include "DataSourceInterface.h"
#include "Client.h"
#include "Emp.h"
#include "Admin.h"

class FileManager : public DataSourceInterface {
private:
    string Cfile = "Client.txt";
    string Efile = "Emp.txt";
    string Afile = "Admin.txt";

public:
    void addClient(Client& client)  {
        fstream file;
        file.open(Cfile, ios::app);
        if (file.is_open()) {
            file << client.getName() << "#" << client.getID() << "#" << client.getBalance() << "#" << client.getPass() << "#" << client.getTotalTrans() << "\n";
            file.close();
        }
    }

    void addEmp(Emp& emp)  {
        fstream file;
        file.open(Efile, ios::app);
        if (file.is_open()) {
            file << emp.getName() << "#" << emp.getID() << "#" << emp.getSalary() << "#" << emp.getPass() << "\n";
            file.close();
        }
    }

    void addAdmin(Admin& admin)  {
        fstream file;
        file.open(Afile, ios::app);
        if (file.is_open()) {
            file << admin.getName() << "#" << admin.getID() << "#" << admin.getSalary() << "#" << admin.getPass() << "\n";
            file.close();
        }
    }

    vector<Client> getAllClients()  {
        vector<Client> clients;
        fstream file;
        file.open(Cfile,ios::in);
        string line;
        while (getline(file, line)) {
            stringstream s(line);
            string name, pass;
            int id;
            double balance;
            getline(s, name, '#');
            getline(s, pass, '#');
            s >> id;
            s >> balance;

            clients.push_back(Client(name, pass, balance, id));
        }
        file.close();
        return clients;
    }

    vector<Emp> getAllEmps() {
        vector<Emp> emps;
        fstream file;
        file.open(Efile,ios::in);
        string line;
        while (getline(file, line)) {
            stringstream s(line);
            string name, pass;
            int id;
            double salary;
            getline(s, name, '#');
            getline(s, pass, '#');
            s >> id;
            s >> salary;

            emps.push_back(Emp(name, pass, salary, id));
        }
        file.close();
        return emps;
    }

    vector<Admin> getAllAdmins()  {
        vector<Admin> admins;
        ifstream file;
        file.open(Afile,ios::in);
        string line;
        while (getline(file, line)) {
            stringstream s(line);
            string name, pass;
            int id;
            double salary;
            getline(s, name, '#');
            getline(s, pass, '#');
            s >> id;
            s >> salary;

            admins.push_back(Admin(name, pass, salary, id));
        }
        file.close();
        return admins;
    }

    void removeAllClients() override {
        ofstream file(Cfile, ios::trunc);
        file.close();
    }

    void removeAllEmps()  {
        ofstream file(Efile, ios::trunc);
        file.close();
    }

    void removeAllAdmins()  {
        ofstream file(Afile, ios::trunc);
        file.close();
    }
};