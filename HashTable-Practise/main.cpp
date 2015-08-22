//
//  main.cpp
//  Hash-Table-Practise
//
//  Created by MichaelShea on 22/8/15.
//  Copyright (c) 2015 MichaelShea. All rights reserved.
//

#include <iostream>
#include "HashTable.h"

using namespace std;

int main( ) {
    HashTable Table1;
    Table1.Insert_item("Hi");
    Table1.Insert_item("Bye");
    Table1.Insert_item("Bye");
    Table1.Insert_item("No");
    Table1.Insert_item("Yo");
    Table1.Insert_item("Lol");
    Table1.Insert_item("fUCK");
    Table1.printTable();
    cout<<"The size of the table is"<<Table1.GetSize()<<endl;
    node*tmp=Table1.Search("Hi");
    cout<<"The item I search is "<<tmp->item;
}
