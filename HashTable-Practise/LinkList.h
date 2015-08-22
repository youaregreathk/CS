//
//  LinkList.h
//  Hash-Table-Practise
//
//  Created by MichaelShea on 22/8/15.
//  Copyright (c) 2015 MichaelShea. All rights reserved.
//


#ifndef __Hash_Table_Practise__LinkList__
#define __Hash_Table_Practise__LinkList__


#include <iostream>
using namespace std;

struct node
{
    string item;
    node* next;
};

class Linklist
{
    private :
        node*head;   //node point to the head of the linklist
        int size;    // the size of the link list
    
    public :
        //Constructor
        Linklist ();
    
        //Adding Nodes
        bool InsertNodesAtFront(string value);
    
        //Getsize of the linklist
        int GetSize();
    
        //Print the linked list
        void print();
    
        //Search for a certain node and return it
        node*search(string val);
    
        //Destructor
        ~Linklist();
};









#endif /* defined(__Hash_Table_Practise__LinkList__) */
