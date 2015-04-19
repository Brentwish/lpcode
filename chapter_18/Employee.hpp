//* * * * * * * * * * * * * * * * * * * * * * * * * * * *
//Project Name: Chapter 17/18 Assignment                *
//Project Description: MultiOperating System Compiling  *
//Project Author: Wishart, Brent                        *
//Is this an extra credit Project: Yes                  *
//Date completed: 04/19/2015                            *
//Operating system used: OSx 10.10.3                    *
//IDE Used: Vi and terminal                             *
//* * * * * * * * * * * * * * * * * * * * * * * * * * * *

//EMPLOYEE.HPP

#ifndef __EMPLOYEE__
#define __EMPLOYEE__

using namespace std;

class Employee {
  private:
  string employee_name;
  int employee_number;

  public:
  //===================================================================
  //Constructors                                                     ||
  //===================================================================
  Employee();
  virtual ~Employee();
  //===================================================================
  //Accessors                                                        ||
  //===================================================================
  string get_employee_name();
  virtual double pay_employee() = 0;
  int get_employee_number();
  virtual void print() = 0;
  //===================================================================
  //Mutators                                                         ||
  //===================================================================
  bool set_employee_name(string emp_name);
  bool set_employee_number(int);
};
#endif
