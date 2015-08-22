//
//  HashTable.cpp
//  Hash-Table-Practise
//
//  Created by MichaelShea on 22/8/15.
//  Copyright (c) 2015 MichaelShea. All rights reserved.
//

#include "HashTable.h"
//Creating a array of type linklist pointer
HashTable :: HashTable ()
{
    tablelength=13;
    array=new Linklist[tablelength];
    
}

int
HashTable::HashFunction(string val)
{
    int value = 0;
    for ( int i = 0; i < val.length(); i++ )
        value += val[i];
    return (value * val.length() ) %tablelength;
}

bool
HashTable::Insert_item(string val)
{
    int index=HashFunction(val);
    array[index].InsertNodesAtFront(val);
    size++;
    return true;
}

int
HashTable::GetSize() {
    return size;
}

void
HashTable::printTable()
{
    for(int i=0;i<tablelength;i++)
    {
        array[i].print();

    }
}

node* HashTable::Search(string val)
{
    node*tmp;
    for(int i=0;i<tablelength;i++)
    {
        tmp=array[i].search(val);
        if(tmp)
            return tmp;
    }
    return NULL;
}

HashTable::~HashTable()
{
    for(int i=0;i<tablelength;i++)
    {
        array[i].~Linklist();
        //cout<<"Deleting"<<endl;
    }
}