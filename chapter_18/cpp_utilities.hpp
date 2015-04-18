//* * * * * * * * * * * * * * * * * * * * * * * * *
//Project Name: Chapter 17 Assignment             *
//Project Description: Linked List implementation *
//Project Author: Wishart, Brent                  *
//Is this an extra credit Project: No             *
//Date completed: 04/09/2015                      *
//Operating system used: OSx 10.10.2              *
//IDE Used: Vi and terminal                       *
//* * * * * * * * * * * * * * * * * * * * * * * * *

//CPP_UTILITIES.HPP

#ifndef __CPPUtilities__utilities__
#define __CPPUtilities__utilities__

#include <iostream>
#include <cmath>
using namespace std;
class Utilities {
  public:
    static string make_upper_case(string);
    static string make_lower_case(string);
    static void clear_cin(void);
    static string input_string(string, int, int);
    template <class T> static T input_num(string, T, T, int);
    static int input_int(string, int, int, int);
    static double input_double(string, double, double, double);
    static string center_string(string, int);
    template <class T> static T get_random_num(T, T, int);
    static int get_random_int(int, int);
    static double get_random_double(int, int, int);
    static float get_random_float(int, int, int);
    static bool verify_action(string);
    static char ask_overwrite(void);
    static string get_random_string(int, int);
    template <class T> static void bubble_sort(T, int);
};

template <class T>
void Utilities::bubble_sort(T the_array, int size) {
  bool is_sorted = false;
  T temp_variable;
  if (size == 0)
    cout << "No entries in array." << endl;
  else {
    while (!is_sorted) {
      is_sorted = true;
      for (unsigned i = 0; i < size - 1; i++) {
        if (the_array[i] > the_array[i + 1]) {
          temp_variable = the_array[i];
          the_array[i] = the_array[i + 1];
          the_array[i + 1] = temp_variable;
          is_sorted = false;
        }
      }//for
    }
    cout << "Array sorted." << endl;
  }
}

template <class T>
T Utilities::input_num(string promptString, T minValue, T maxValue, int exitValue) {
  T userInput;
  cout << promptString << " \n";
  while (true) {
    cin >> userInput;
    if (!cin.fail()) {
      char myChar = cin.peek();
      if (myChar == '\n')
        if ((userInput >= minValue && userInput <= maxValue) || userInput == exitValue)
          break;
        else {
          cout << "Invalid value entered.  Should be between " << minValue << " and " << maxValue << " Please try again\n";
          clear_cin();
        }//else
        else {
          cout << "Invalid value entered.  Should be between " << minValue << " and " << maxValue << " Please try again\n";
          clear_cin();
        }//else
    }//if
    else {
        cout << "Invalid integer value entered. Please try again.\n";
        clear_cin();
    }//else
  }
  clear_cin();
  return userInput;
}//input_num

template <class T>
T Utilities::get_random_num(T Min, T Max, int decimalPlaces) {
    T returnNum;
    T tempInt;
    T tempDouble;

    while (true) {
        returnNum = ((double)rand()/RAND_MAX);
        tempInt = (returnNum * Max)*(pow(10, decimalPlaces));
        tempDouble = static_cast<T>(tempInt)/(pow(10, decimalPlaces));
        if (tempDouble >= Min)
            break;
        else {}
    }//while
    return tempDouble;
}

#endif /* defined(__CPPUtilities__utilities__) */
