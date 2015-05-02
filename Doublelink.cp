#include <iostream>
using namespace std;

class Node
{
    friend class The_entire_List;
private:
    
    int data=0;
    Node*next;
    Node*prev;
public:
    Node(int v)
    {
        data=v;
        next=NULL;
        prev=NULL;
    }
    int getval()
    {
        return data;
    }
};

class The_entire_List
{
private:
    
    int size=0;
    Node*head=NULL;
    Node*tail=NULL;
    
    
public:
    
    void addinfront(int v)   //Add Front
    {
        
        if(head==NULL)     //case 1. Empty list
        {
            Node* ptr= new Node(v);
            head=ptr;
            tail=ptr;
            
            
        }
        else              //case 2. Not an empty list
        {
            Node* prr= new Node(v);
            prr->next=head;
            head->prev=prr;
            head=prr;
        }
        size++;
    }
    void addafter(int x,int y)   //Add after
    {
        Node*ptr;
        for(ptr=head;ptr!=NULL&&ptr->getval()!=x;ptr=ptr->next)
            ;
        if(ptr!=NULL)
        {
            //case 1 the number is the last number in the list
            if(ptr->next==NULL)
            {
                Node* tmp= new Node(y);
                tmp->prev=tail;
                ptr->next=tmp;
                tail=tmp;
            }
            //case 2 the number is in somewhere in the list, but not the last item
            else
            {
                Node* tmp= new Node(y);
                tmp->next=ptr->next;
                tmp->prev=ptr;
                ptr->next=tmp;
                tmp->next->prev=tmp;
            }
            size++;
        }
        else
            cout<<"There is no such item in the list";
    }
    void search(int v)
    {
        Node*ptr;
        int count=0;
        for(ptr=head;ptr!=NULL;ptr=ptr->next)
        {
            if(ptr->getval()==v)
                count++;
        }
        if(count)
        {
            cout<<"The value "<<v<< " appear "<<count<<" times in the list"<<endl;
            
        }
        else
        {
            cout<<"There is no such value in the list"<<endl;
        }
    }
    void addlast(int v)
    {
        //case1 if the list is empty
        if(head==NULL)
        {
            Node* tmp= new Node(v);
            head=tmp;
            tail=tmp;
        }
        //case 2 if the list is not empty
        else{
            Node* tmp= new Node(v);
            tmp->prev=tail;
            tail->next=tmp;
            tail=tmp;
        }
        size++;
    }
    void deletefont()
    {
        //case 1. empty list
        if(head==NULL)
        {
            cout<<"Empty list Cannot delete"<<endl;
        }
        //case 2. 1 element list
        else if(head->next==NULL)
        {
            tail=NULL;
            delete head;
            head=NULL;
        }
        //case 3 the list has more than 1 element
        else{
            Node*tmp;
            tmp=head->next;
            delete head;
            head=tmp;
            head->prev=NULL;
        }
        size--;
    }
    void deleteitem(int v)
    {
        Node* ptr;
        for(ptr=head;ptr!=NULL&&ptr->getval()!=v;ptr=ptr->next)
            ;
        if(ptr!=NULL)
        {
            //case 1 cur is pointing at the first item of the list
            if(ptr==head)
            {
                //case the list only has one item
                if(head->next==NULL)
                {
                    tail=NULL;
                    delete head;
                    head=NULL;
                }
                else{
                    Node*tmp;
                    tmp=head->next;
                    delete head;
                    head=tmp;
                    head->prev=NULL;
                }
            }
            
            //case 2 cur is pointing at the last item and more than 1 itme
            else if(ptr->next==NULL)
            {
                tail=ptr->prev;
                delete ptr;
                tail->next=NULL;
            }
            //case 3 cur is pointing some item in a list moe
            else{
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr->prev;
                delete ptr;
            }
            size--;
        }
        else
            cout<<"No such item";
        
    }
    void print()
    {
        Node*tmpt;
        for(tmpt=head;tmpt!=NULL;tmpt=tmpt->next)
        {
            cout<<tmpt->getval()<<" ";
        }
    }
    
    void printsize()
    {
        cout<<endl<<"The size of the list is: "<<size<<endl;
    }
};


int main()
{
    The_entire_List list;
    list.addinfront(0);
    list.addlast(1);
    list.addlast(2);
    list.addlast(3);
    list.addlast(4);
    list.print();
    list.printsize();
    list.deleteitem(4);
    list.print();
    list.printsize();
    list.deleteitem(2);
    list.print();
    list.printsize();
    list.deleteitem(4);
    list.print();
    list.printsize();
    list.deleteitem(0);
    list.print();
    list.printsize();
    list.deleteitem(3);
    list.print();
    list.printsize();
    list.deleteitem(1);
    list.print();
    list.printsize();
    /*
     list.addinfront(3);
     list.addinfront(2);
     list.addinfront(1);
     list.print();
     list.printsize();
     list.deleteitem(3);
     list.print();
     list.printsize();
     list.deleteitem(1);
     list.print();
     list.printsize();
     list.deleteitem(2);
     list.print();
     list.printsize();
     */
}
