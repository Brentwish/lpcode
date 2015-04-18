//* * * * * * * * * * * * * * * * * * * * * * * * *
//Project Name: Chapter 17 Assignment             *
//Project Description: Linked List implementation *
//Project Author: Wishart, Brent                  *
//Is this an extra credit Project: No             *
//Date completed: 04/09/2015                      *
//Operating system used: OSx 10.10.2              *
//IDE Used: Vi and terminal                       *
//* * * * * * * * * * * * * * * * * * * * * * * * *

//EMPLOYEE.CPP

#include <iostream>
#include "Employee.hpp"
#include "cpp_utilities.hpp"

using namespace std;
//===================================================================
//Constructors                                                     ||
//===================================================================
Employee::Employee() {
  employee_name = "";
  employee_number = 0;
}
Employee::~Employee() {
  cout << "Employee deleted" << endl;
}
//===================================================================
//Accessors                                                        ||
//===================================================================
string Employee::get_employee_name() {
  return employee_name;
}
int Employee::get_employee_number() {
  return employee_number;
}
//===================================================================
//Mutators                                                         ||
//===================================================================
bool Employee::set_employee_name(string emp_name) {

  if (emp_name.size() < 1 || emp_name.size() > 32) {
    cout << "Invalid number of characters entered. (1 - 32)\n";
    return false;
  }

  else {
    employee_name = emp_name; 
    return true;
  }
}

bool Employee::set_employee_number(int input) {
  if ((input < 0) || (input > 9999)) {
    cout << "Invalid employee number, must be between 0 and 9999\n";
    return false;
  }
  else {
    employee_number = input;
    return true;
  }
}
