//
//  main.cpp
//  stringprogram.cpp
//
//  Created by Joseph Priest on 10/25/13.
//  Copyright (c) 2013 Joseph Priest. All rights reserved.
//
//  This program will take somebody's name that is formated like this: Last, First Middle
//  and format it to look like this: First M LAST. This program is very limited and relies
//  realies heavely on a correctly formatted input.
//
//  Possible Update:
//  -input error checking including formatting
//  -acceptance of multiple formats "Google Corrections", for any input recieved
//  -creation of class or addition to library for name formatting
//  -Time/Space trimming
//
//

#include <iostream> //Grabbing all of the resources
#include <string>
#include <cstdlib>
using namespace std;


void inputData(string &myString)  // This method will be passed a string variable and will fill it in
{
    string last, first, middle; //Easy eay to segment *possible t/s trim
    cout << "Please enter your string\n";
    getline(cin, myString); //cin >> stops at next blank space so I used getline *Still used cin
    
    //Block for last name
    int pos = myString.find(",", 0); // Look for comma and index
    last = myString.substr(0, pos); // Store the last name
    
    //Block for first name
    int pos2 = pos +2; //To copy over it's contents
    pos = myString.find(" ", pos2); //This will look for the next space after the following comma
    first = myString.substr(pos2, pos-pos2); // Store the first name
    
    
    //Block for Middle name
    pos2 = pos + pos2; // Move the index to the right spot
    middle = myString.substr(pos +1 , 1); // Store middle name
    
    string random= "Erase me!";
    random = random.erase(0, 3); //erases three letters
    
    //Now that I've got all of these peices i've got to put them back together.
    myString =  first + " " +  middle + " " +  last;
    
}
void outputData(string myString) // ...Just prints some string
{
    cout << myString << "\n";
}


int main() // Where it all happens!
{
    string myString;
    inputData(myString);
    outputData(myString);
    system("Pause"); // I've read that this is terriably ineffcient due to the set up and tear down required in order to have it do this system call. Also, this is platform specific so on my mac it just causes an error
    
    return 0;
}