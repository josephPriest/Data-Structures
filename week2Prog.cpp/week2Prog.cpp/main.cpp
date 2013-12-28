//
//  main.cpp
//  week2Prog.cpp
//  Data Structures Class
//  HW 2
//  Created by Joseph Priest on 11/1/13.
//  Copyright (c) 2013 Joseph Priest. All rights reserved.
//
//
//  This program is designed to show how to recursily call a function to achieve an end
//
//
//
//
//

#include <iostream> //Grabbing all of the resources
#include <cstdlib>
using namespace std;

int holder =0; //Global variable to hold the extra stuff
//  This function is designed to call itself untill the sum has been reached for whatever number
int sumDigits(int num){
    if ( num > 0 ) {
        holder += num % 10; // The remainder is dumped into global to track sum
        num /= 10; //  num gets reduced by place 10 until
        sumDigits(num); // Recursive call
    }
    num = holder;
    return num;
}
int main(int argc, const char * argv[])
{

    int num, stop=0;
    //Added the ability to keep adding numbers together
    while(stop == 0){
    cout << "Please enter an integer that you would like the sum of digits for:\n";
    cin >> num;
    num = sumDigits(num);
    cout << "Your sum is " << num <<".\n";
    cout << "Would you like to continue? Enter anything beside 0 to quit:\n";
    cin >> stop;
    num =0;
    }
    system("PAUSE");
    return 0;
    
    return 0;
}

