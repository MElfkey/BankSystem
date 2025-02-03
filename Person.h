#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {	
	//Att:
protected:
	string name;
	int id;
	string pass;
	static int lastID;

public:
	//Cons:
	Person();
	Person(string name, string pass);
	//Setters:
	void setName(string name);
	void setPass(string pass);
	//Getters:
	string getName();
	string getPass();
	int getID();
	//Methods:
		//1- Create ID:
	static int createID();
	//2- ID Organization:
	static string idOrg(int id);
	//3- Name Organization:
		//Remove any unwanted characters.
	string nameOrg(string name);
	//4- displayMessage:
	void displayMessage();
};

#endif

