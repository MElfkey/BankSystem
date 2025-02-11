#include "Person.h"
#include "Emp.h"
#include "Client.h"
#include "Admin.h"
#include "FilesHelper.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


void displayMessage() {
    cout << "Welcome to our Bank System, " << "!\n";
    cout << "We have an excellent team ready to assist you at any time!!." << endl;
    cout << "We provide 24/7 and hope our service meets your satisfaction and approval." << endl;
    cout << endl;
    cout << "if you are an employee e" << endl;

    
}
int main()
{
   // displayMessage();

    FilesHelper file;
    Emp e,e1;
    Admin a;
    Client c;


    //file.getEmployees();
  //  a.addClient(c);
   // file.SaveClient(c);
  /* a.addEmp(e);
    a.addEmp(e1);
    file.SaveEmp("Emp.txt", e);
    file.SaveEmp("Emp.txt", e1);*/




}

