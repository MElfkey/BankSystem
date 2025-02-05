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
 string nameOrg(string name) {
    while (true) {
        bool isValid = true;
	
        for (int i = 0; i < name.length(); i++) {
            if (!(isalpha(name[i]) || name[i] == ' ')) {
                isValid = false;
                break;
            }
        }
	
        if (!isValid) {
            cout << "Invalid input. Please enter a valid name (only letters and spaces, up to 20 characters): " << endl;
            getline(cin, name);
            continue;
        }
	
        int counter = 0;
        bool inword = false;
        for (int i = 0; i < name.length(); i++) {
            if (name[i] != ' ') {
                if (!inword) {
                    if (counter > 0) {
                        name += ' ';
                    }
                    counter++;
                    inword = true;
                }
            }
            else {
                inword = false;
            }
        }
	
        if (counter > 3) {
            int spaceCount = 0;
            for (int i = 0; i < name.length(); i++) {
                if (name[i] == ' ') {
                    spaceCount++;
                    if (spaceCount >= 3) {
                        name.erase(i);
                        break;
                    }
                }
            }
        }
	
        if (name.length() > 20) {
            cout << "Name is too long, it must be 20 or fewer characters. Truncating to 20 characters. \n" ;
           
            cout << "(only letters and spaces, up to 20 characters) : \n";
            getline(cin, name);
            continue;
        }
	
        break;
    }
	
    return name;
} 
//4- displayMessage:
void Person::displayMessage() {
	cout << "Welcome to our Bank System, Mr\ " << getName() << "!\n";
	cout << "Your ID is: " << idOrg(getID()) << endl;
	cout << "We have an excellent team ready to assist you at any time!!." << endl;
	cout << "We provide 24/7 and hope our service meets your satisfaction and approval." << endl;
	cout << endl;
}
