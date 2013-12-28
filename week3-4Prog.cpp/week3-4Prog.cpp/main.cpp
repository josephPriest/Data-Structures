//
//  main.cpp
//  week3-4Prog.cpp
//
//  Created by Joseph Priest on 11/10/13.
//  Copyright (c) 2013 Joseph Priest. All rights reserved.
//
/*  This program will store in miniVector v a list of 15 random integers from 0 to 99, then it will output the vector, sort the vector, then output it again sorted
*/
//  As a side note to this project, I'm not sure if this was an intentional error or if it was
//  was just overlooked but the random.h file had some mathmatical probelms that had to be fixed
//  for this program to run correctly. I took the portion with the delegation of seedin limitations and took the ratio and lowered it to stay within the correct number of digits within the execution.
//


#include <iostream>
#include "d_random.h"
#include "d_vector.h"



// output miniVector v
template <typename T>
void writeMiniVector(const miniVector<T> v)
{
    for (int i=0; i < v.size(); i++ ){
        cout << v[i] << "\n\n" ;
    }
    
    
};
         
// use insertion sort to place miniVector v in descending order
template <typename T>
void sortMiniVector(miniVector<T> & v)
{
        int i, j, key, numLength = v.size( );
        for(j = 1; j < numLength; j++)    // Start with 1 (not 0)
        {
            key = v[j];
            for(i = j - 1; (i >= 0) && (v[i] < key); i--)   // Smaller values move up
            {
                v[i+1] = v[i];
            }
            v[i+1] = key;    //Put key into its proper location
        }
        return;

    
};



int main(int argc, const char * argv[])
{
    int i, limit = 100;
    miniVector<int> v;
    randomNumber rnd;
    
    for (i=0; i <15; i++)
    {
    v.push_back(rnd.random(limit));
    }
    writeMiniVector(v);
    sortMiniVector(v);
    writeMiniVector(v);
    system("PAUSE");
    
    
    return 0;
}

