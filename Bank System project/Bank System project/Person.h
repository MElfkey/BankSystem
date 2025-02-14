#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string pass;
    static int lastID;

public:
    Person();
    Person(string name, string pass, int id);

    void setName(string name);
    void setPass(string pass);
    string getName();
    int getID();
    string getPass();

    static int createID();
    static string idOrg(int id);
    string nameOrg(string name);

 
    ~Person();
};

