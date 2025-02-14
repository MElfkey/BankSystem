#include "Person.h"

// Initialize static member
int Person::lastID = 1000000000;

// Default constructor
Person::Person() {
    this->id = createID();
}

// Parameterized constructor
Person::Person(string name, string pass, int id) {
    this->name = name;
    this->id = createID();
    this->pass = pass;
}

// Setters
void Person::setName(string name) {
    this->name = nameOrg(name);
}

void Person::setPass(string pass) {
    this->pass = pass;
}

// Getters
string Person::getName() {
    return name;
}

int Person::getID() {
    return id;
}

string Person::getPass() {
    return pass;
}

// Create ID
int Person::createID() {
    lastID += 1;
    return lastID;
}

// ID Organization
string Person::idOrg(int id) {
    string idStr = to_string(id);
    // Pad with leading zeros to ensure it's exactly 8 digits
    while (idStr.length() < 8) {
        idStr.insert(0, "0");
    }
    return idStr;
}

// Name Organization
string Person::nameOrg(string name) {
    while (true) {
        bool isValid = true;

        for (int i = 0; i < name.length(); i++) {
            if (!(isalpha(name[i]) || name[i] == ' ')) {
                isValid = false;
                break;
            }
        }

        if (!isValid) {
            cout << "Invalid input. Please enter a valid name (only letters and spaces, exactly 3 words): " << endl;
            getline(cin, name);
            continue;
        }

        int wordCount = 0;
        bool inWord = false;
        for (int i = 0; i < name.length(); i++) {
            if (name[i] != ' ') {
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            }
            else {
                inWord = false;
            }
        }

        if (wordCount != 3) {
            cout << "Name must consist of exactly 3 words. Please try again." << endl;
            getline(cin, name);
            continue;
        }

        size_t first = name.find_first_not_of(" ");
        size_t last = name.find_last_not_of(" ");
        name = name.substr(first, (last - first + 1));

        break;
    }

    return name;
}
// Destructor
Person::~Person() {
}