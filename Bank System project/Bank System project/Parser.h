#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "Client.h"
#include "Emp.h"
#include "Admin.h"

class Parser {
public:
    static std::vector<std::string> split(std::string& line) {
        std::vector<std::string> result;
        std::stringstream s(line);
        std::string item;
        while (getline(s, item, '#')) {
            result.push_back(item);
        }
        return result;
    }

    static Client parseToClient(std::string& line) {
        std::vector<std::string> parts = split(line);
        std::string name = parts[0];
        int id = std::stoi(parts[1]);
        std::string pass = parts[2];
        double balance = std::stod(parts[3]);
        return Client(name, pass, balance, id);
    }

    static Emp parseToEmp(std::string& line) {
        std::vector<std::string> parts = split(line);
        std::string name = parts[0];
        int id = std::stoi(parts[1]);
        std::string pass = parts[2];
        double salary = std::stod(parts[3]);
        return Emp(name, pass, salary, id);
    }

    static Admin parseToAdmin(std::string& line) {
        std::vector<std::string> parts = split(line);
        std::string name = parts[0];
        int id = std::stoi(parts[1]);
        std::string pass = parts[2];
        double salary = std::stod(parts[3]);
        return Admin(name, pass, salary, id);
    }
};