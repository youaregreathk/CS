//
//  HashTable.h
//  Hash-Table-Practise
//
//  Created by MichaelShea on 22/8/15.
//  Copyright (c) 2015 MichaelShea. All rights reserved.
//

#ifndef Hash_Table_Practise_HashTable_h
#define Hash_Table_Practise_HashTable_h

#include "LinkList.h"
#include<iostream>

using namespace std;


class HashTable
{
  private:
    int HashFunction(string val);
    Linklist* array;
    int tablelength;
    int size;
    
    int hash(string itemkey);
  
  public:
    //Constructor
    HashTable();
    
    //Insert Item
    bool Insert_item(string val);
    
    //Get the total size of the hash table
    int GetSize();
    
    //Print the hash table
    void printTable();
    
    //Search if the hash table contain a particular string retunr NULL if it doesnt
    node*Search(string val);
    
    ~HashTable();
};

#endif
