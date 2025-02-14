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
        fstream file;
        file.open(fileName,ios::app);
        file << id;
        file.close();
    }

    static int getLast(string fileName) {
        fstream file;
        file.open(fileName,ios::in);
        int lastId;
        file >> lastId;
        file.close();
        return lastId;
    }

    static void SaveClient(Client c) {
        fstream file;
        file.open("Client.txt", ios::app);
        file << c.getName() << "#" << c.getID() << "#" << c.getPass() << "#" << c.getBalance() << "\n";
        file.close();
    }

    static void SaveEmp(Emp e) {
       
        fstream file;
        file.open("Emp.txt", ios::app);
        file << e.getName() << "#" << e.getID() << "#" << e.getPass() << "#" << e.getSalary() << "\n";
        file.close();
       
    }

    static vector<Client> getClients() {
        fstream file;
        file.open("Client.txt",ios::in);
        vector<Client> c;
        string line;
        while (getline(file, line)) {
            c.push_back(Parser::parseToClient(line));
        }
        file.close();
         return c;

    }

    static vector<Emp> getEmployees() {
        fstream file;
        file.open("Emp.txt",ios::in);
        vector<Emp> emps;
        string line;
        while (getline(file, line)) {
            emps.push_back(Parser::parseToEmp(line));
        }
        file.close();
        return emps;
    }

    static vector<Admin> getAdmins() {
        fstream file;
        file.open("Admin.txt",ios::in);
        vector<Admin> admins;
        string line;
        while (getline(file, line)) {
            admins.push_back(Parser::parseToAdmin(line));
        }
        file.close();
        return admins;
    }

    static void clearFile(string fileName, string lastIdFile) {
        fstream file;
        file.open(fileName, ios::trunc);
        file.close();
        saveLast(lastIdFile, 0);
    }
};
