#include<iostream>
using namespace std;

class Node{
    friend class queue;
   private:
     int value;
     Node*next;
     Node*prev;
   
   public:
    Node()
    {
        next=NULL;
        prev=NULL;
    }
    Node(int v)
    {
        value=v;
        next=NULL;
        prev=NULL;
    }
    int getvalue() const
    {
        return value;
    }
};

class queue{
    private:
     Node*head;
    int siize=0;
    public:
     queue()   //create a dummy note
    {
        Node*tmp=new Node();
        tmp->next=tmp;
        tmp->prev=tmp;
        head=tmp;
    }
    
    void push(int v)
    {
        Node*tmp=new Node(v);
        tmp->next=head;
        tmp->prev=head->prev;
        head->prev->next=tmp;
        head->prev=tmp;
        siize++;
    }
    void pop()
    {
        if(head->next!=head)
        {
            Node*tmp=head->next->next;
            delete head->next;
            head->next=tmp;
            tmp->prev=head;
            siize--;
        }
        else{
            cout<<"The quene is already empty"<<endl;
        }
    }
    int size() const
    {
        return siize;
    }
    bool isEmpty() const
    {
        if(siize)
            return true;
        else
            return false;
    }
    void front() const
    {
        if(head->next!=head)
            cout<< head->next->getvalue()<<endl;
      
    }
    ~ queue()
    {
        Node* cur;
        Node* prev=NULL;
        for(cur=head->next;cur!=head;prev=cur,cur=cur->next)
        {
            delete prev;
            cout<<"hi";
        }
        delete head;
    }
    
};

int main()
{
    queue q;
    
    
    
    
}