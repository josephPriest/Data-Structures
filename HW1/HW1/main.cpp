//
//  main.cpp
//  HW1
//
//  Created by Joseph Priest on 10/25/13.
//  Copyright (c) 2013 Joseph Priest. All rights reserved.
//  Using only find(), length(), and substr() I need to abstract a peice of the a string

#include <iostream> //including the standard C++ library iostream class
#include <string> //including the standard C++ library string class
using namespace std; //just says we are using the standard library



int main ()
{
    
    string s = "Happy Holiday"; // The main phrase which I need to rescue 'Holiday' from
    int posHappy, posEnd;
    posHappy = s.find("Holiday"); // Get the begining of the word
    posEnd  = s.find('y', posHappy); // Get the end
    string newString = s.substr(posHappy,  7);
    cout << "\nYour new string is " << newString << "\n\n";
    return 0; //since our main is expecting us to return an int, we return zero.
    
}
