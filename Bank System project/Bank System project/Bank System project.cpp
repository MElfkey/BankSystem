#include "Person.h"
#include "Emp.h"
#include "Client.h"
#include "Admin.h"
#include "FilesHelper.h"
#include <fstream>
#include <vector>

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

    /*Admin a;
    Emp e,e1;

    a.addEmp(e);
    a.addEmp(e1);*/

    FilesHelper file;
    /*file.SaveEmp(e);
    file.SaveEmp(e1);*/

    file.getEmployees();




}

