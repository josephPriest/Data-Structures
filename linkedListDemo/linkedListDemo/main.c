//
//  main.c
//  linkedListDemo
//
//  Created by Joseph Priest on 12/14/13.
//  Copyright (c) 2013 Joseph Priest. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node{
    int x;
    struct node *next;
    
};

int main(int argc, const char * argv[])
{
    struct node *root;
    
    root = (struct node*) malloc(sizeof(struct node));
    root->next =0;
    root->x=5;
    
    
    
    return 0;
}

