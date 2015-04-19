//* * * * * * * * * * * * * * * * * * * * * * * * * * * *
//Project Name: Chapter 17/18 Assignment                *
//Project Description: MultiOperating System Compiling  *
//Project Author: Wishart, Brent                        *
//Is this an extra credit Project: Yes                  *
//Date completed: 04/19/2015                            *
//Operating system used: OSx 10.10.3                    *
//IDE Used: Vi and terminal                             *
//* * * * * * * * * * * * * * * * * * * * * * * * * * * *

//SHIFT_SUPERVISOR.CPP

#include <iostream>
#include "Employee.hpp"
#include "Shift_supervisor.hpp"
#include "cpp_utilities.hpp"

using namespace std;
//===================================================================
//Constructors                                                     ||
//===================================================================
Shift_supervisor::Shift_supervisor() {
  annual_salary = 0;
  production_bonus = 0;
}
//===================================================================
//Accessors                                                        ||
//===================================================================
double Shift_supervisor::get_annual_salary() {
  return annual_salary;
}
double Shift_supervisor::get_production_bonus() {
  return production_bonus;
}
double Shift_supervisor::pay_employee() {
  double pay = annual_salary + production_bonus;
  return pay;
}
void Shift_supervisor::print() {
  cout << "\nSHIFT SUPERVISOR PAY CHART\n\n";
  cout << "Shift Supervisor's name :              " << get_employee_name() << endl;
  cout << "Shift Supervisor's number:             " << get_employee_number() << endl;
  cout << "Shift Supervisor's annual salary:      " << get_annual_salary() << endl;
  cout << "Shift Supervisor's production bonus:   " << get_production_bonus() << endl;
  cout << "Shift Supervisor's annual pay:         " << pay_employee() << endl;
  cout << endl;
}
//===================================================================
//Mutators                                                         ||
//===================================================================
bool Shift_supervisor::set_annual_salary(double salary) {

  if (salary < 0 || salary > 1000000) {
    cout << "Invalid annual salary entered, must be between 0 and 1,000,000\n"; 
    return false;
  }

  else {
    annual_salary = salary;
    return true;
  }
}

bool Shift_supervisor::set_production_bonus(double bonus) {

  if (bonus < 0 || bonus > 1000000) {
    cout << "Invalid production bonus value, must be between 0 and 1,000,000\n"; 
    return false;
  }

  else {
    production_bonus = bonus;
    return true;
  }
}
