//
//  main.cpp
//  quickie
//
//  Created by Joseph Priest on 11/11/13.
//  Copyright (c) 2013 Joseph Priest. All rights reserved.
//

#include <iostream>
#include <list>
int main(int argc, const char * argv[])
{
    
    stack<int> stk;
    
    int x = 3, y = 19;
    
    
    
    stk.push(6);
    
    stk.push(x);
    
    stk.push(y);
    
    cout << stk.top();
    
    for (std::list<int>::iterator it=alist.begin(); it != alist.end(); ++it)
        std::cout << ' ' << *it;

    return 0;
}

