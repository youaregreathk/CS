//
//  LinkList.cpp
//  Hash-Table-Practise
//
//  Created by MichaelShea on 22/8/15.
//  Copyright (c) 2015 MichaelShea. All rights reserved.
//

#include "LinkList.h"

Linklist::Linklist()
{
    head=NULL;
    size=0;
}

bool Linklist:: InsertNodesAtFront(string tmp)
{
    node* ptr=new node();
    ptr->item=tmp;
    
    if(head== NULL){   //case the linklist is empty
        head=ptr;
        ptr->next= NULL;
      }
    else {              //case the linkist is not empty
        ptr->next=head;
        head=ptr;
    }
    size++;
    return true;
}

int Linklist::GetSize()
{
    return size;
}

void Linklist::print()
{
    node*tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->item<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}
node* Linklist::search(string val)
{
    node*tmp=head;
    while(tmp)
    {
        if(tmp->item== val)
            return tmp;
        tmp=tmp->next;
    }
    return NULL;
}
Linklist::~Linklist()
{
    node* cur=head;
    node*prev=NULL;
    while(cur!=NULL)
    {
        delete prev;
        prev=cur;
        cur=cur->next;
    }
}