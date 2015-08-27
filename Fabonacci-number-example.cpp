/
//  main.cpp
//  fabonocci_dp
//
//  Created by MichaelShea on 26/8/15.
//  Copyright (c) 2015 MichaelShea. All rights reserved.
//

#include <iostream>
using namespace std;

int Sarray[100]={0};    //Global array

int fabonocci(int n)   //Divide and Conquer
{
  if(n<=2)
    return 1;
  else
    return fabonocci(n-1)+fabonocci(n-2);
}

int fabonocci_dp(int n)    //Using Dynamic Programming
{
  if( Sarray[n] > 0)
    return Sarray[n];
  if(n<=2)
    return 1;
  else
    {
      Sarray[n]= fabonocci(n-1)+fabonocci(n-2);
      return Sarray[n];
    }
    
}

int fab(int n)
{
  int fab_arr[n+1];
  fab_arr[0]=0;
  fab_arr[1]=1;
  for(int i=2;i<=n;i++)
    {
      fab_arr[i]=fab_arr[i-1]+fab_arr[i-2];
    }
    
  return fab_arr[n];
}

int main() {
  int n=6;
    
  cout<<fabonocci_dp(n);
  return 0;
}
