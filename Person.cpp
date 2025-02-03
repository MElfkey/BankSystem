#include "Person.h"
//Cons:

Person::Person() : id(0), pass("") {}

Person::Person(string name, string pass) {
	this->name = name;
	this->id = createID();
	setPass(pass);
}
//Setters:
void Person::setName(string name) {
	this->name = nameOrg(name);
}

void Person::setPass(string pass) {
	while (pass.length() != 7) {
		cout << "Password must be exactly 7 characters long. Try again: ";
		getline(cin, pass);
	}
	this->pass = pass;
}

//Getters:

string Person::getName() {
	return name;
}

int Person::getID() {
	return id;
}

string Person::getPass() {
	return pass;
}

//Methods:
		//1- Create ID:
int Person::lastID = 10000000;
 int Person:: createID() {
	lastID += 7;
	return lastID;
}
 //2- ID Organization:
 string Person::idOrg(int id)
 {
	 string idStr = to_string(id);
	 if (idStr.length() < 8) {
		 idStr.insert(0, 8 - idStr.length(), '0');
	 }
	 return idStr;
 }

//3- Name Organization:
		//Remove any unwanted characters.
string Person::nameOrg(string name) {
	for (int i = 0; i < name.length(); i++) {
		if (!isalpha(name[i]) && name[i] != ' ') {
			name.erase(i, 1);
			i--;
		}
	}
	//Reduce the number of words to a maximum of 3 words.
	int spaceCount = 0;
	for (int i = 0; i < name.length(); i++) {
		if (name[i] == ' ') {
			spaceCount++;
			if (spaceCount >= 3) {
				name.erase(i); //Remove everything after the third distance
				break;
			}
		}
	}
	//Reduce name length to 20 characters maximum
	if (name.length() > 20) {
		name = name.substr(0, 20); //Take only the first 20 characters.
	}
	return name;
}
//4- displayMessage:
void Person::displayMessage() {
	cout << "Welcome to our Bank System, " << getName() << "!\n";
	cout << "Your ID is: " << idOrg(getID()) << endl;
	cout << "We have an excellent team ready to assist you at any time!!." << endl;
	cout << "We provide 24/7 and hope our service meets your satisfaction and approval." << endl;
	cout << endl;
}
