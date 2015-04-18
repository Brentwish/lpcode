//* * * * * * * * * * * * * * * * * * * * * * * * *
//Project Name: Chapter 17 Assignment             *
//Project Description: Linked List implementation *
//Project Author: Wishart, Brent                  *
//Is this an extra credit Project: No             *
//Date completed: 04/09/2015                      *
//Operating system used: OSx 10.10.2              *
//IDE Used: Vi and terminal                       *
//* * * * * * * * * * * * * * * * * * * * * * * * *

//CPP_UTILITIES.CPP

#include <stdio.h>
#include <cstdlib>
#include "cpp_utilities.hpp"
#include <ctime>
#ifdef __MINGW32__
  #include <windows.h>
#elif __APPLE__
  #include "TargetConditionals.h"
  #if TARGET_OS_MAC
  #endif
#elif __linux__
#endif

string Utilities::make_upper_case(string theString) {

    locale settings;
    string newString;

    for(short i = 0; i < theString.size(); ++i)
        newString += (toupper(theString[i], settings));

    return newString;

}//make_upper_case


string Utilities::make_lower_case(string theString) {

    locale settings;
    string newString;

    for(short i = 0; i < theString.size(); ++i)
        newString += (tolower(theString[i], settings));

    return newString;

}//make_upper_case


void Utilities::clear_cin(void) {
    cin.clear();
    cin.ignore(32768, '\n');
    return;
}//clear_cin


string Utilities::input_string(string promptString, int minLength, int maxLength) {
    string userInput;

    while (true) {
        cout << promptString << "\n";
        getline(cin, userInput);
        if (userInput.size() < minLength || userInput.size() > maxLength) {
            cout << "The string you entered is too short or too long.  Should be " << minLength << " to " << maxLength << " in Length\n";
            cout << "Please try again\n";
        }//if
        else
            break;
    }//while
    return userInput;
}//input_string

int Utilities::input_int(string promptString, int minValue, int maxValue, int exitValue) {
  int userInput;

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
}//input_int


double Utilities::input_double(string promptString, double minValue, double maxValue, double exitValue) {
    double userInput;

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
            cout << "Invalid double value entered. Please try again.\n";
            clear_cin();
        }//else
    }
    clear_cin();
    return userInput;
}//inputdouble

//
//Send a string and center it in a returned string
//
string Utilities::center_string(string stringToCenter, int toWidth)
{
    string outputString;
    int l = 0;
    int pos = 0;

    l = static_cast<int>(stringToCenter.length());
    pos=(toWidth-l)/2;
    for(int i=0;i<pos;i++) {
        outputString = outputString + " ";
    }//for
    outputString = outputString + stringToCenter;
    return outputString;
}//center_string

//
// This function will return a random integer no larger than Max
//
int Utilities::get_random_int(int Min, int Max) {
    int tempInt = 0;

    while (true) {
        tempInt = rand() % Max;
        if (tempInt >= Min)
            break;
        else {}
    }//while

    return tempInt;
}//get_random_int

//
//This function will return a random double with 2 decimal digits, and not greater than Max
//
double Utilities::get_random_double(int Min, int Max, int decimalPlaces) {
    double returnNum;
    int tempInt;
    double tempDouble;

    while (true) {
        returnNum = ((double)rand()/RAND_MAX);
        tempInt = (returnNum * Max)*(pow(10, decimalPlaces));
        tempDouble = static_cast<double>(tempInt)/(pow(10, decimalPlaces));
        if (tempDouble >= Min)
            break;
        else {}
    }//while
    return tempDouble;
}//get_random_double

float Utilities::get_random_float(int Min, int Max, int decimalPlaces) {
    float returnNum;
    int tempInt;
    float tempFloat;

    while (true) {
        returnNum = ((float)rand()/RAND_MAX);
        tempInt = (returnNum * Max)*(pow(10, decimalPlaces));
        tempFloat = static_cast<float>(tempInt)/(pow(10, decimalPlaces));
        if (tempFloat >= Min)
            break;
        else {}
    }//while
    return tempFloat;
}

string Utilities::get_random_string(int Min, int Max) {
    string tempString;

    int size = get_random_int(Min, Max);
    for (int ctr=0; ctr<size; ctr++) {
        char tempChar = get_random_int(97, 122);
        tempString += tempChar;
    }//for

    return tempString;
}//get_random_string

//
//Display a prompt asking the user if they want to
//sort the vector ascending or descening.
//
bool Utilities::verify_action(string userPrompt) {
    char userInput;
    bool returnValue = false;

    while (true) {
        cout << "\n";
        cout << userPrompt << "\n";
        cout << "<Y>es, <N>o ==> ";
        cin >> userInput;
        if (toupper(userInput) == 'Y') {
            returnValue = true;
            break;
        }//if
        else if (toupper(userInput) == 'N') {
            returnValue = false;
            break;
        }//else if
        else {
            cout << "Invalid selection, please try again\n";
        }//else
        clear_cin();
    }//while

    clear_cin();
    return returnValue;
}//verify_action

//
//Ask the user if they want to append, overwrite or quit the read operation
//
char Utilities::ask_overwrite(void) {
    char userChoice;

    cout << "You already have data loaded into the system\n";
    cout << "Do you want to (O)verwrite, (A)ppend or (Q)uit? ";
    cin >> userChoice;
    switch (toupper(userChoice)) {
        case 'O': {
            break;
        }//case O
        case 'A':
            break;
        case 'Q':
        default: {
            cout << "Operation Aborted\n";
            return 'Q';
        }//default
    }//switch

    return toupper(userChoice);

}//askOverwrite
