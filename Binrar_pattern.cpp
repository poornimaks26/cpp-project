#include <iostream>

using namespace std;

class solution

{

public:

void pattern11(int n)
{
 int start = 1;

 for(int i =0;i<=n;i++)
 {

    //for odd row value start with 1 and even row with 0 value
    if(i%2 == 0)
    start =1;

    else

    start = 0;

  for(int j=0;j<=i;j++){
    //cout<<j;
    //j=0 
    //j=1-->0,1
    //j=2--->0,1,2
    //j=3--->0.1.2,3

    cout<<start;
    
    //j=0 means even start = 1
    //j=1 means odd column 0 vlue 1 --->0,0
    //j=2 means even--->1,1,1
    //j=3 means odd--->0,0,0,0

    start=1-start;

    //j=2 --->1.1,1
    //alread strat is 1 --->1(j[0])
    //flip 1-strt--->0(j[1])
    //flip 1-0---->1(j[2])
    

  }
 
  cout<<endl;
 }
}

};

int main()
{
    int n =3;

    solution sol;

    sol.pattern11(n);

    return 0;
}