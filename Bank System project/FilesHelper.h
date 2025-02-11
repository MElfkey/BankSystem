#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Client.h"
#include "Emp.h"
#include "Admin.h"
#include "Parser.h"

using namespace std; 

class FilesHelper {
public:
    static void saveLast(string fileName, int id) {
        ofstream file(fileName);
        file << id;
        file.close();
    }

    static int getLast(string fileName) {
        ifstream file(fileName);
        int lastId;
        file >> lastId;
        file.close();
        return lastId;
    }

    static void SaveClient(Client c) {
        ofstream file("Client.txt", ios::app);
        file << c.getName() << "#" << c.getID() << "#" << c.getPass() << "#" << c.getBalance() << "\n";
        file.close();
    }

    static void SaveEmp(string fileName, Emp e) {
       
        ofstream file(fileName, ios::app);
        file << e.getName() << "#" << e.getID() << "#" << e.getPass() << "#" << e.getSalary() << "\n";
        file.close();
       
    }

    static vector<Client> getClients() {
        ifstream file("Client.txt");
        vector<Client> c;
        string line;
        while (getline(file, line)) {
            c.push_back(Parser::parseToClient(line));
        }
        file.close();
        return c;
    }

    static vector<Emp> getEmployees() {
        ifstream file("Emp.txt");
        vector<Emp> emps;
        string line;
        while (getline(file, line)) {
            emps.push_back(Parser::parseToEmp(line));
        }
        file.close();
        return emps;
    }

    static vector<Admin> getAdmins() {
        ifstream file("Admin.txt");
        vector<Admin> admins;
        string line;
        while (getline(file, line)) {
            admins.push_back(Parser::parseToAdmin(line));
        }
        file.close();
        return admins;
    }

    static void clearFile(string fileName, string lastIdFile) {
        ofstream file(fileName, ios::trunc);
        file.close();
        saveLast(lastIdFile, 0);
    }
};
