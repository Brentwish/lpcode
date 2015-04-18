//* * * * * * * * * * * * * * * * * * * * * * * * *
//Project Name: Chapter 17 Assignment             *
//Project Description: Linked List implementation *
//Project Author: Wishart, Brent                  *
//Is this an extra credit Project: No             *
//Date completed: 04/09/2015                      *
//Operating system used: OSx 10.10.2              *
//IDE Used: Vi and terminal                       *
//* * * * * * * * * * * * * * * * * * * * * * * * *

//SHIFT_SUPERVISOR.HPP

#ifndef __SHIFT__SUPERVISOR__
#define __SHIFT__SUPERVISOR__

using namespace std;

class Shift_supervisor : public Employee {
  private :
    double annual_salary;
    double production_bonus;
  public :
    //===================================================================
    //Constructors                                                     ||
    //===================================================================
    Shift_supervisor();
    ~Shift_supervisor(){}
    //===================================================================
    //Accessors                                                        ||
    //===================================================================
    double get_annual_salary();
    double get_production_bonus();
    virtual double pay_employee();
    virtual void print();
    //===================================================================
    //Mutators                                                         ||
    //===================================================================
    bool set_annual_salary(double salary);
    bool set_production_bonus(double bonus);
    };
#endif
