//* * * * * * * * * * * * * * * * * * * * * * * * *
//Project Name: Chapter 17 Assignment             *
//Project Description: Linked List implementation *
//Project Author: Wishart, Brent                  *
//Is this an extra credit Project: No             *
//Date completed: 04/09/2015                      *
//Operating system used: OSx 10.10.2              *
//IDE Used: Vi and terminal                       *
//* * * * * * * * * * * * * * * * * * * * * * * * *

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
