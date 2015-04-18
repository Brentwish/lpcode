//* * * * * * * * * * * * * * * * * * * * * * * * *
//Project Name: Chapter 17 Assignment             *
//Project Description: Linked List implementation *
//Project Author: Wishart, Brent                  *
//Is this an extra credit Project: No             *
//Date completed: 04/09/2015                      *
//Operating system used: OSx 10.10.2              *
//IDE Used: Vi and terminal                       *
//* * * * * * * * * * * * * * * * * * * * * * * * *

//TEAM_LEADER.HPP

#ifndef __TEAM__LEADER__
#define __TEAM__LEADER__

using namespace std;

class Team_leader : public Production_worker {
  private:
    double monthly_bonus;
    int required_training_hours;
    int attended_training_hours;
  public:
    //===================================================================
    //Constructors                                                     ||
    //===================================================================
    Team_leader();
    ~Team_leader(){}
    //===================================================================
    //Accessors                                                        ||
    //===================================================================
    double get_monthly_bonus();
    int get_required_training_hours();
    int get_attended_training_hours();
    virtual double pay_employee();
    virtual void print();
    //===================================================================
    //Mutators                                                         ||
    //===================================================================
    bool set_monthly_bonus(double bonus);
    bool set_required_training_hours(int req_hours);
    bool set_attended_training_hours(int att_hours);
};
#endif
