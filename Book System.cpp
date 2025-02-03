#include <iostream>
#include<string>
#include"Person.h"
#include"Client.h"
#include"Emp.h"
#include"Admin.h"
using namespace std;

int main()
{
	Client c1, c2;
	Emp e;
	Admin a;
	string name,pass;
	double salary{};


	//e.addClient(c1, name,pass);
	
	a.addEmp(e, name, pass,salary);
	e.displayInfo();

 return 0;
}
