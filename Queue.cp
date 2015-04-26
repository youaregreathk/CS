#include<iostream>
using namespace std;

class cirarray
{
   private:
    int ssize=0;
    int MAX;
    int*array=new int[MAX];
    int first_position=0;
    int last_position=0;

   public:
    cirarray(int x)
    {
        MAX=x;
    }
    void enqueue( int v )
    {
        
        if(ssize==0)          //add first item into the queue
        {
            array[first_position]=v;
            ssize++;
        }
        else{
            last_position++;
            if(ssize!=MAX)
            {
               if(last_position==MAX)  //case 2 circular
                 {
                    //cout<<"you are there";
                    if((last_position%MAX)<first_position)
                       {
                         array[last_position%MAX]=v;
                         last_position=last_position%MAX;
                         ssize++;
                       }
                 }
            
               else
                  {
                     //cout<<"here";
                     array[last_position]=v;
                     ssize++;
                  }
            }
               else
                   cout<<"Array is Full, Can not added";
            }
    
    }
      void dequeue()
    {
      if(first_position!=last_position)
      {
          if(first_position==4)  //case 2 circular
          {
              first_position=0;
              ssize--;
          }
          else
          {
             ssize--;
             first_position++;
          }
          
      }
        
      else
        {
            cout<<"Cannot dequeue array is empty";
        }
        
    };
      int size()
    {
        return ssize;
    }
      int front()
    {
        return array[first_position];
    }
    
};

int main()
{
    cirarray a(5);
    
    
}