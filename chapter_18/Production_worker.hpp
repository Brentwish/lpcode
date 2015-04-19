//* * * * * * * * * * * * * * * * * * * * * * * * * * * *
//Project Name: Chapter 17/18 Assignment                *
//Project Description: MultiOperating System Compiling  *
//Project Author: Wishart, Brent                        *
//Is this an extra credit Project: Yes                  *
//Date completed: 04/19/2015                            *
//Operating system used: OSx 10.10.3                    *
//IDE Used: Vi and terminal                             *
//* * * * * * * * * * * * * * * * * * * * * * * * * * * *

//PRODUCTION_WORKER.HPP

#ifndef __PRODUCTION_WORKER__
#define __PRODUCTION_WORKER__

using namespace std;

class Production_worker : public Employee {
  private:
  int shift;
  double pay_rate;

  public:
  //===================================================================
  //Constructors                                                     ||
  //===================================================================
  Production_worker();
  ~Production_worker(){}
  //===================================================================
  //Accessors                                                        ||
  //===================================================================
  int get_shift();
  double get_pay_rate();
  virtual double pay_employee();
  virtual void print();
  //===================================================================
  //Mutators                                                         ||
  //===================================================================
  bool set_shift(int input);
  bool set_pay_rate(double pay);
};
#endif
