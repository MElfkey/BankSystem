#include "Client.h"

Client::Client() : balance(0.0) {}

Client::Client(string name, string pass, double balance) : Person(name, pass)
{
	this->balance = balance;
}

void Client::setBalance(double balance) {
	this->balance = balance;
}

double Client::getBalance() {
	return balance;
}

void Client::deposit() {
	double amount;
	while (true) {
		cout << "Enter your amount to deposit: \n";
		cin >> amount;
		if (amount > 50 && amount <= 160000) {
			balance += amount;
			cout << "Your balance after deposit is: " << balance << endl;
			break;
		}
		else if (amount > 160000) {
			cout << "You can't deposit more than 160000 at once. Please enter a valid amount.\n";
		}
		else {
			cout << "You can't deposit less than 50. Please enter a valid amount.\n";
		}
	}
	num_deposite++;
	total_trans++;
}

void Client::withdraw() {
	double amount;
	while (true) {
		cout << "Enter your amount to withdraw: \n";
		cin >> amount;
		if (amount > 50 && amount <= 16000) {
			if (amount <= balance) {
				balance -= amount;
				cout << "Your balance after withdrawal is: " << balance << endl;
				break;
			}
			else {
				cout << "You don't have enough balance to withdraw this amount. Please enter a valid amount.\n";
			}
		}
		else if (amount > 16000) {
			cout << "You can't withdraw more than 16000 at once. Please enter a valid amount.\n";
		}
		else {
			cout << "You can't withdraw less than 50. Please enter a valid amount.\n";
		}
	}
	total_trans++;
}

void Client::transferTo(Client& client) {
	double amount;
	while (true) {
		cout << "Enter the amount you want to transfer: \n";
		cin >> amount;
		if (amount > 50 && amount <= 16000) {
			if (amount <= balance) {
				balance -= amount;
				client.balance += amount;
				cout << "Your balance after transfer is: " << balance << endl;
				break;
			}
			else {
				cout << "You don't have enough balance to transfer this amount. Please enter a valid amount.\n";
			}
		}
		else if (amount > 16000) {
			cout << "You can't transfer more than 16000 at once. Please enter a valid amount.\n";
		}
		else {
			cout << "You can't transfer less than 50. Please enter a valid amount.\n";
		}
	}
	total_trans++;
}

int Client::benefits()
{
	if (balance >= 20000 && num_deposite >= 10)
		balance *= 0.13;

	return balance;
}

void Client::CheckBalance()
{
	cout << "Your balance is : " << getBalance() << endl;

}

void Client::display()
{
	cout << "The user name is : " << getName() << endl;
	cout << "The user id is : " << getID() << endl;
	cout << "The user balance is : " << getBalance() << endl;
	cout << "The number of transactions the user do : " << total_trans << endl;

}
