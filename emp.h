#pragma once
#include "Person.h"
#include "Client.h"

class Emp : public Person
 {
	protected:
		double salary;

	public:
		// Constructors
		Emp();

		Emp(string name, string pass, double salary);

		// Setters
		void setSalary(double salary);

		// Getters
		double getSalary();

		// Methods
		void addClient(Client& client);

		void searchClient(Client clients[], int size, int searchID);
		void displayInfo();
};

