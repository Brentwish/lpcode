//* * * * * * * * * * * * * * * * * * * * * * * * * * * *
//Project Name: Chapter 17/18 Assignment                *
//Project Description: MultiOperating System Compiling  *
//Project Author: Wishart, Brent                        *
//Is this an extra credit Project: Yes                  *
//Date completed: 04/19/2015                            *
//Operating system used: OSx 10.10.3                    *
//IDE Used: Vi and terminal                             *
//* * * * * * * * * * * * * * * * * * * * * * * * * * * *

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
    static int input_int(string, int, int, int);
    static double input_double(string, double, double, double);
    static string center_string(string, int);
    static int get_random_int(int, int);
    static double get_random_double(int, int, int);
    static float get_random_float(int, int, int);
    static bool verify_action(string);
    static char ask_overwrite(void);
    static string get_random_string(int, int);
};
#endif /* defined(__CPPUtilities__utilities__) */
