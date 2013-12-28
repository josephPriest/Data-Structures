//
//  main.cpp
//  week5-6Prog
//
//  Created by Joseph Priest on 12/1/13.
//  Copyright (c) 2013 Joseph Priest. All rights reserved.
//
//  This program is designed to show a linked list and use functions to insert new elements and delete
//  them. It first defines a structure for the addresses, then a class, and finally instantiates them and
//  inserts new names into them.
//
//

#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;
using namespace std;

//Structure for the node
struct AddressNode                       //one element of list
{
    string name;                    //String for the names
    AddressNode* next;              //Pointer to next spot
};//end struct node
//Class for the book
class ABook{
private:
    AddressNode* topPtr;                    //pointer to first link
public:ABook()                    //default constructor
    {
    topPtr = NULL; }            //note that it's empty
    ~ABook();      //clear it out
    void Insert(string NewItem);   // Add new item
    void SortedInsert(string NewItem);//Insert with a sort
    void Remove(string& item); /* Remove element from top of the stack and return the item.*/
    void print();//print All items
};



ABook::~ABook(){
    //deletes all the elements in the last as long as its not empty
    AddressNode* thisOne = topPtr;
    while( topPtr != NULL )
    {
        thisOne=topPtr->next;
        delete topPtr;
        topPtr=thisOne;
    }
}



void ABook::Insert(string NewItem){
    //add items to linked list
    AddressNode* newNode = new AddressNode();          //make a new node contain new item
    newNode->name = NewItem;                  //give it data
    newNode->next = topPtr;                   //it points to next link
    topPtr = newNode;                         //now first points to this
    
}


void ABook::SortedInsert(string NewItem){
    AddressNode* newNode = new AddressNode();          //new item
    newNode->name = NewItem;                  //put data into it
    newNode->next=NULL;
    AddressNode* thisOne = topPtr;       //first space
    if(topPtr==NULL){
        topPtr=newNode;
        return;
    }
    if(NewItem.compare(topPtr->name) <= 0){
        newNode->next=topPtr;
        topPtr=newNode;
    }
    else{
        AddressNode *ptr = topPtr;
        if( ptr->next == NULL ){    // Reached end without inserting
            ptr->next = newNode;       // Insert at end
            newNode->next = NULL;
            return;
        }
        do{
            
            if(NewItem.compare(ptr->next->name) <= 0){
                newNode->next = ptr->next;  // Insert item after ptr
                ptr->next = newNode;
                break;
            }
            ptr = ptr->next ;
            if( ptr->next == NULL ){    // Reached end without inserting
                ptr->next = newNode;       // Insert at end
                newNode->next = NULL;
                break;
            }
        }while(ptr->next != NULL);
        
    }
}

void ABook::Remove(string& item){
    AddressNode* thisOne = topPtr;       //set ptr to first link
    if(item.compare(topPtr->name)==0){
        topPtr=topPtr->next;
        return;
    }
    while( thisOne->next != NULL )           //quit on last link
    {
        if(item.compare(thisOne->next->name)!=0)thisOne = thisOne->next;           //move to next link
        else thisOne->next=thisOne->next->next;
    }
}


void ABook::print(){
    AddressNode* thisOne = topPtr;       //set ptr to first link
    if(topPtr==NULL){
        cout<<"List is null\n";
        return;
    }
    cout<<"Sorted List: "<<endl;
    while( thisOne != NULL )           //quit on last link
    {
        cout << thisOne->name << endl;     //print data
        thisOne = thisOne->next;           //move to next link
    }
    cout<<endl;
}

int main(int argc, char** argv) {
    ABook Book;       //make linked list
    string nameToRemove1("Precious");
    string nameToRemove2("Eileen");
    string nameToRemove3("Frank");
    string nameToRemove4("Ken");
    Book.Insert("Precious");     // Insert Precious into list.
    Book.SortedInsert("Eileen"); // Insert Eileen into list (sorted)
    Book.SortedInsert("Frank");  // Insert Frank into list (sorted)
    Book.SortedInsert("Ken");    // Insert Ken into listed (sorted)
    Book.print();
    Book.Remove(nameToRemove1);
    Book.print();
    Book.Remove(nameToRemove2);
    Book.print();
    Book.Remove(nameToRemove3);
    Book.print();
    Book.Remove(nameToRemove4);
    Book.print();
    system("pause");
    return 0;
}