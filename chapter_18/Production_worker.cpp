//* * * * * * * * * * * * * * * * * * * * * * * * * * * *
//Project Name: Chapter 17/18 Assignment                *
//Project Description: MultiOperating System Compiling  *
//Project Author: Wishart, Brent                        *
//Is this an extra credit Project: Yes                  *
//Date completed: 04/19/2015                            *
//Operating system used: OSx 10.10.3                    *
//IDE Used: Vi and terminal                             *
//* * * * * * * * * * * * * * * * * * * * * * * * * * * *

//PRODUCTION_WORKER.CPP

#include <iostream>
#include "Employee.hpp"
#include "Production_worker.hpp"
#include "cpp_utilities.hpp"

using namespace std;
//===================================================================
//Constructors                                                     ||
//===================================================================
Production_worker::Production_worker() {
  shift = 1;
  pay_rate = 0;
}
//===================================================================
//Accessors                                                        ||
//===================================================================
int Production_worker::get_shift() {
  return shift;
}
double Production_worker::get_pay_rate() {
  return pay_rate;
}
double Production_worker::pay_employee() {
  double pay = pay_rate * 8 * 5 * 52; //Pay rate multiplied by hours, days, and weeks
  return pay;
}
void Production_worker::print() {
  cout << "\nPRODUCTION WORKER PAY CHART\n\n";
  cout << "Production worker's name :             " << get_employee_name() << endl;
  cout << "Production worker's number:            " << get_employee_number() << endl;
  cout << "Production worker's shift number:      " << get_shift() << endl;
  cout << "Production worker's pay_rate:          " << get_pay_rate() << endl;
  cout << "Production worker's annual pay:        " << pay_employee() << endl;
  cout << endl;
}
//===================================================================
//Mutators                                                         ||
//===================================================================
bool Production_worker::set_shift(int input) {
  if ((input < 1) || (input > 2)) {
    cout << "Invalid Shift, must be either 1 or 2\n";
    return false;
  }
  else {
    shift = input;
    return true;
  }
}

bool Production_worker::set_pay_rate(double pay) {
  if ((pay < 0) || (pay > 500)) {
    cout << "Invalid Pay Rate, must be between 0 and 500\n";
    return false;
  }
  else {
    pay_rate = pay;
    return true;
  }
}
