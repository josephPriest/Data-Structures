//
//  main.cpp
//  week7Prog.cpp
//
//  Created by Joseph Priest on 12/8/13.
//  Copyright (c) 2013 Joseph Priest. All rights reserved.
//
//
//
//
//  This program is designed to accept 6 numbers and allow them to be searched from the
//  user. The program uses a standard binary tree with a insertion algorithm to place them
//  in the correct locations. This program also implements the binary search which
//  searches through each element to look for the user's inputed number and tells them
//  wether it was there or not.
//



#include<iostream>
using namespace std;

// My structure for the nodes, one in front and behind
struct node
{
    int number;
    struct node *left; //Pointers to left and right
    struct node * right;
};

//Method for inserting a newnode
void insertnewnode(int number,struct node * present)
{
    struct node *temp; //Pointer to temporary
    temp=(struct node*)malloc(sizeof(struct node)); //allocate the size of node
    temp->number=number;
    // conditionals to place the new node in the correct area
    if(present->number >number)
    {
        if(present->left==NULL)
        {
            present->left=temp;
        }
        else
        {
            insertnewnode(number,present->left);
        }
    }
    if(present->number <number)
    {
        if(present->right==NULL)
        {
            present->right=temp;
        }
        else
        {
            insertnewnode(number,present->right);
        }
    }
    
    
    
}
// Method for checking for the node and returning either true or false
void searchnode(int number,struct node * present)
{
    if(present->number==number)
    {
        cout<<"It's there!"<<endl;
    }
    if(present->number >number)
    {
        if(present->left==NULL)
        {
            cout<<"There dosen't seem to be anything here..."<<endl;
        }
        else
        {
            searchnode(number,present->left); //recursive call to check other side
        }
    }
    if(present->number <number)
    {
        if(present->right==NULL)
        {
            cout<<"There dosen't seem to be anything here..."<<endl;
        }
        else
        {
            searchnode(number,present->right); //recursive call check the other side
        }
    }
    
}
//Main execution of code
int main()
{
    int i,j,number;
    struct node *root;
    cout<<"Enter the numbers that you wish to use: ";
    root=(struct node*)malloc(sizeof(struct node)); //Initiate struct
    cin>>root->number; //Take first number
    for(i=0;i<5;i++)//Loop for five more elements
    {
        cin>>number;
        insertnewnode(number,root); //insert them into the correct locations
    }
    int p=2;
    while(p--)
    {
        cout<<"Which integer are you looking for? ";
        cin >>number;
        searchnode(number,root); //Call our search method
    }
}