//* * * * * * * * * * * * * * * * * * * * * * * * *
//Project Name: Chapter 17 Assignment             *
//Project Description: Linked List implementation *
//Project Author: Wishart, Brent                  *
//Is this an extra credit Project: No             *
//Date completed: 04/09/2015                      *
//Operating system used: OSx 10.10.2              *
//IDE Used: Vi and terminal                       *
//* * * * * * * * * * * * * * * * * * * * * * * * *

//TEAM_LEADER.CPP

#include <iostream>
#include "Employee.hpp"
#include "Production_worker.hpp"
#include "Team_leader.hpp"
#include "cpp_utilities.hpp"

using namespace std;
//===================================================================
//Constructors                                                     ||
//===================================================================
Team_leader::Team_leader() {
  monthly_bonus = 0;
  required_training_hours = 0;
  attended_training_hours = 0;
}
//===================================================================
//Accessors                                                        ||
//===================================================================
double Team_leader::get_monthly_bonus() {
  return monthly_bonus;
}
int Team_leader::get_required_training_hours() {
  return required_training_hours;
}
int Team_leader::get_attended_training_hours() {
  return attended_training_hours;
}
double Team_leader::pay_employee() {
  double pay = (get_pay_rate() * 8 * 5 * 52) + (monthly_bonus * 12);
  return pay;
}
void Team_leader::print() {
  cout << "\nTEAM LEADER PAY CHART\n\n";
  cout << "Team Leader's name :                   " << get_employee_name() << endl;
  cout << "Team Leader's number:                  " << get_employee_number() << endl;
  cout << "Team Leader's shift number:            " << get_shift() << endl;
  cout << "Team Leader's required training hours: " << get_required_training_hours() << endl;
  cout << "Team Leader's attended training hours: " << get_attended_training_hours() << endl;
  cout << "Team Leader's pay rate:                " << get_pay_rate() << endl;
  cout << "Team Leader's monthly bonus:           " << get_monthly_bonus() << endl;
  cout << "Team Leader's annual pay:              " << pay_employee() << endl;
  cout << endl;
}
//===================================================================
//Mutators                                                         ||
//===================================================================
bool Team_leader::set_monthly_bonus(double bonus) {

  if (bonus < 0 || bonus > 25000) {
    cout << "Invalid monthly bonus value, must be between 0 and 25,000\n";
    return false;
  }

  else {
    monthly_bonus = bonus;
    return true;
  }
}
bool Team_leader::set_required_training_hours(int req_hours) {

  if (req_hours < 0 || req_hours > 250) {
    cout << "Invalid input, required training hours must be between 0 and 250\n";
    return false;
  }

  else {
    required_training_hours = req_hours;
    return true;
  }
}

bool Team_leader::set_attended_training_hours(int att_hours) {
  if (att_hours < 0 || att_hours > 250) {
    cout << "Invalid input, attended training hours must be between 0 and 250\n";
    return false;
  }

  else {
    attended_training_hours = att_hours;
    return true;
  }
}
