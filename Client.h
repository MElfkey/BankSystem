#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"

class Client : public Person {
	double balance;
	int total_trans = 0;
	int num_deposite = 0;

public:
	Client();
	Client(string name, string pass, double balance);
	void setBalance(double balance);
	double getBalance();
	void deposit();
	void withdraw();
	void transferTo(Client& client);
	int benefits();
	void CheckBalance();
	void display();
};

#endif 

