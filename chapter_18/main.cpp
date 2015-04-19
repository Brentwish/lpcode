//* * * * * * * * * * * * * * * * * * * * * * * * * * * *
//Project Name: Chapter 17/18 Assignment                *
//Project Description: MultiOperating System Compiling  *
//Project Author: Wishart, Brent                        *
//Is this an extra credit Project: Yes                  *
//Date completed: 04/19/2015                            *
//Operating system used: OSx 10.10.3                    *
//IDE Used: Vi and terminal                             *
//* * * * * * * * * * * * * * * * * * * * * * * * * * * *

//MAIN.CPP


#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string>
#include "Employee.hpp"
#include "Production_worker.hpp"
#include "Shift_supervisor.hpp"
#include "Team_leader.hpp"
#include "Linked_list.hpp"
#include "cpp_utilities.hpp"

//Patch for the to_string function when running Windows
#ifdef __MINGW32__

#include <cstdlib>
#include <windows.h>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
#endif

Employee *get_new_employee(Linked_list<Employee> *emp_list);
string menu_select();
void print_menu();
void print_emp(Employee*);

using namespace std;

int main(int argc, const char *argv[]) {
  for (int i = 0; i < argc; i++) {
    cout << "parameter " << i + 1 << " is : " << argv[i];
    cout << "\n";
  }
  if (argc != 2) {
    cout << "ERROR:\nInvalid number of arguments, 1 argument required for Stack/Que size.\n";
    return 0;
  }
  else {
    Linked_list<Employee> emp_list;
    Employee *emp;
    string user_input = "";
    bool exit_flag = true;

    print_menu();
    while (exit_flag) {
      user_input = menu_select();

      if (user_input == "A") {
        cout << "Append Employee Selected\n\n";
        int current = emp_list.nodes_from_current();
        emp = get_new_employee(&emp_list);
        emp_list.append(emp);
        emp_list.set_current_position(current);
        cout << "Employee appended\n";
        cout << emp_list.get_num_nodes() << " employees in list.\n";
      }

      else if (user_input == "I") {
        cout << "Insert Employee Selected\n\n";
        emp = get_new_employee(&emp_list);
        emp_list.insert(emp);
        cout << "Employee inserted\n";
        cout << emp_list.get_num_nodes() << " employees in list.\n";
      }

      else if (user_input == "R") {
        cout << "Remove Employee Selected\n\n";
        int input;
        bool flag = true;
        if (emp_list.get_num_nodes() == 0) {
          cout << "No employees to remove\n";
        }
        else {
          int count = 0;
          cout << "Current employee numbers\n";
          emp_list.reset_current();
          emp = emp_list.get_current_data();
          //Outputs each employee number for ease of use
          while (count != emp_list.get_num_nodes()) {
            cout << emp->get_employee_number() << endl;
            emp_list.forward();
            emp = emp_list.get_current_data();
            count++;
          }
          input = Utilities::input_int("Please enter the employee number of the employee you would like to remove: ", 0, 9999, -999);
          emp_list.reset_current();
          emp = emp_list.get_current_data();
          //Runs through list checking emp numbers.
          //If found, while loop breaks, else flag = false
          while (!emp || emp->get_employee_number() != input) {
            if (emp_list.forward()) {
              emp = emp_list.get_current_data();
            }
            else {
              cout << "Employee number does not exist" << endl;
              flag = false;
              break;
            }
          }
          if (flag) {
            emp_list.remove(emp);
          }
        }
      }

      else if (user_input == "S") {
        cout << "Set List Position Selected\n\n";

        int num_emp = emp_list.get_num_nodes();
        string emp_from_current;
        string num_emp_string;
        string prompt;

        #ifdef __MINGW32__
          emp_from_current = patch::to_string(emp_list.nodes_from_current() + 1);
          num_emp_string = patch::to_string(num_emp);
        #elif __APPLE__
          num_emp_string = to_string(num_emp);
          emp_from_current = to_string(emp_list.nodes_from_current() + 1);
        #endif

        if (num_emp == 0) {
          cout << num_emp << " employees in list.\n";
        }

        else {
          cout << num_emp << " employees in list.\n";
          prompt = "Please enter the list position you would like to go to\n(note: 1 = head of list, " + num_emp_string + " = tail of list\n" + "Current Position: " + emp_from_current;
          emp_list.set_current_position(Utilities::input_int(prompt, 1, num_emp, -999));
        }
      }

      else if (user_input == "C") {
        cout << "Get current position selected\n\n";
        if (emp_list.get_num_nodes() == 0) {
          cout << "No Nodes in List\n";
        }

        else {
          cout << "Current Position: " << emp_list.nodes_from_current() + 1 << endl;
        }
      }

      else if (user_input == "N") {
        cout << "Get number of employees selected\n\n";
        cout << "Number of Employees: " << emp_list.get_num_nodes() << "\n";
      }

      else if (user_input == "B") {
        cout << "Move Back Selected\n\n";
        if (!emp_list.backward()) {
          cout << "Already at head\n";
        }
      }

      else if (user_input == "F") {
        cout << "Move Forward Selected\n\n";
        if (!emp_list.forward()) {
          cout << "Already at tail\n";
        }
      }

      else if (user_input == "P") {
        cout << "Print Current Employee Selected\n\n";
        emp_list.print_current(&print_emp);
      }

      else if (user_input == "L") {
        cout << "Print List Selected\n\n";
        emp_list.print_all(&print_emp);
      }

      else if (user_input == "M") {
        print_menu();
      }

      else if (user_input == "Q") {
        exit_flag = false;
      }

      else {
        cout << "Invalid Selection, please select a bracketed character from the menu above.\n";
      }
    }
    #ifdef __MINGW32__
      cout << "Bye Bye from Windows\n\n";
    #elif __APPLE__
      cout << "Good Bye from the Mac!\n\n";
    #elif __linux__
      cout << "Bye Bye from Linux\n\n";
    #endif
    return 0;
  }
}

string menu_select() {
  while (true) {
    string temp_input = "";
    cout << "Input: ";
    cin >> temp_input;
    if (temp_input.length() != 1) {
      cout << "Input must be one character in length." << endl;
      Utilities::clear_cin();
    }
    else {
      return Utilities::make_upper_case(temp_input);
    }
  }
}

Employee *get_new_employee(Linked_list<Employee> *emp_list) {
  int emp_type;   //Sets emp to be either a proworker, shiftsuper, or teamleader
  int selection;  //Keeps track of whether or not they selected random or not
  Employee *emp;
  cout << "1) Production Worker                                      " << endl;
  cout << "2) Shift Supervisor                                       " << endl;
  cout << "3) Team Leader                                            " << endl;
  cout << "4) Random Employee with Random attributes                 " << endl;
  selection = Utilities::input_int("Please enter the type of employee you would like to enter.", 1, 4, -999);

  if (selection == 1 || selection == 2 || selection == 3) {
    emp_type = selection;
  }
  else if (selection == 4) {
    emp_type = Utilities::get_random_int(1, 4);
  }

  if (emp_type == 1) {
    emp = new Production_worker;
  }
  else if (emp_type == 2) {
    emp = new Shift_supervisor;
  }
  else if (emp_type == 3) {
    emp = new Team_leader;
  }

  //Sets random, nonspecific employee values
  if (selection == 4) {
    emp->set_employee_name("Random Employee");

    bool flag = true;
    int rand_num;
    emp_list->reset_current();
    Employee *temp_emp = emp_list->get_current_data();
    while(flag) {
      rand_num = Utilities::get_random_int(1, 9999);
      if (!temp_emp) {
        flag = false;
      }
      emp_list->reset_current();
      temp_emp = emp_list->get_current_data();
      for (int i = 0; i < emp_list->get_num_nodes(); i++) {
        if (temp_emp->get_employee_number() == rand_num) {
          flag = true;
          break;
        }
        else {
          if (!emp_list->forward()) {
            flag = false;
            break;
          }
          temp_emp = emp_list->get_current_data();
        }
      }
    }
    emp->set_employee_number(rand_num);
    //Sets random values for production worker if selected
    if (emp_type == 1) {
      dynamic_cast<Production_worker*>(emp)->set_shift(Utilities::get_random_int(1, 2));
      dynamic_cast<Production_worker*>(emp)->set_pay_rate(Utilities::get_random_double(0, 500, 2));
    }

    //Sets random values for shift supervisor if selected
    else if (emp_type == 2) {
      dynamic_cast<Shift_supervisor*>(emp)->set_annual_salary(Utilities::get_random_double(0, 250000, 2));
      dynamic_cast<Shift_supervisor*>(emp)->set_production_bonus(Utilities::get_random_double(0, 25000, 2));
    }

    //Sets values for team leader if selected
    else if (emp_type == 3) {
      dynamic_cast<Team_leader*>(emp)->set_required_training_hours(Utilities::get_random_int(1, 250));
      dynamic_cast<Team_leader*>(emp)->set_attended_training_hours(Utilities::get_random_int(1, 250));
      dynamic_cast<Team_leader*>(emp)->set_pay_rate(Utilities::get_random_double(0, 500, 2));
      dynamic_cast<Team_leader*>(emp)->set_monthly_bonus(Utilities::get_random_double(0, 25000, 2));
    }
  }
  
  else {
    //Sets nonspecific employee values
    emp->set_employee_name(Utilities::input_string("Please enter the employee's full name.", 1, 32));

    emp_list->reset_current();
    Employee *temp_emp = emp_list->get_current_data();
    int temp_num;
    bool flag = true;
    while (flag) {
      temp_num = Utilities::input_int("Please enter the employee's number", 0, 9999, -999);
      if (!temp_emp) {
        flag = false;
      }
      emp_list->reset_current();
      temp_emp = emp_list->get_current_data();
      for (int i = 0; i < emp_list->get_num_nodes(); i++) {
        if (temp_emp->get_employee_number() == temp_num) {
          cout << "Employee number is already taken.\n";
          flag = true;
          break;
        }
        else {
          if (!emp_list->forward()) {
            flag = false;
            break;
          }
          temp_emp = emp_list->get_current_data();
        }
      }
    }
    emp->set_employee_number(temp_num);

    //Sets values for production worker if selected
    if (emp_type == 1) {
      dynamic_cast<Production_worker*>(emp)->set_shift(Utilities::input_int("Please enter the employee's shift", 1, 2, -999));
      dynamic_cast<Production_worker*>(emp)->set_pay_rate(Utilities::input_double("Please enter the employee's pay rate", 0, 500, -999));
    }

    //Sets values for shift supervisor if selected
    else if (emp_type == 2) {
      dynamic_cast<Shift_supervisor*>(emp)->set_annual_salary(Utilities::input_double("Please enter the employee's annual salary", 0, 250000, -999));
      dynamic_cast<Shift_supervisor*>(emp)->set_production_bonus(Utilities::input_double("Please enter the employee's production bonus", 0, 25000, -999));
    }

    //Sets values for team leader if selected
    else if (emp_type == 3) {
      dynamic_cast<Team_leader*>(emp)->set_required_training_hours(Utilities::input_int("Please enter the employee's required training hours", 0, 250, -999));
      dynamic_cast<Team_leader*>(emp)->set_attended_training_hours(Utilities::input_int("Please enter the employee's attended training hours", 0, 250, -999));
      dynamic_cast<Team_leader*>(emp)->set_pay_rate(Utilities::input_double("Please enter the employee's pay rate", 0, 500, -999));
      dynamic_cast<Team_leader*>(emp)->set_monthly_bonus(Utilities::input_double("Please enter the employee's monthly bonus", 0, 25000, -999));
    }
  }

  return emp;
}

void print_menu() {
  cout << "* * * * * * * * * * * * * * * * * * * *" << endl;
  cout << "*  <A>ppend an employee to the list   *" << endl;
  cout << "*  <I>nsert an employee in the list   *" << endl;
  cout << "*  <R>emove an employee in the list   *" << endl;
  cout << "*  Get <c>urrent list position        *" << endl;
  cout << "*  <S>et current list position        *" << endl;
  cout << "*  Get <n>umber of employees          *" << endl;
  cout << "*  Move <b>ack in the List            *" << endl;
  cout << "*  Move <f>orward in the list         *" << endl;
  cout << "*  <P>rint the current list employee  *" << endl;
  cout << "*  Print all employees in the <l>ist  *" << endl;
  cout << "*  Reference <m>enu                   *" << endl;
  cout << "*  <Q>uit the program                 *" << endl;
  cout << "*                                     *" << endl;
  cout << "* * * * * * * * * * * * * * * * * * * *" << endl;
}

void print_emp(Employee* emp) {
  emp->print();
}
