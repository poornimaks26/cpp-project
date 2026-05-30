#include <iostream>

using namespace std;

class solution
{

    public:

    void pattern9(int n)
    {
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
            for(int j=0;j<2*i+1;j++)
        {
              cout<<"*";
        }
            for(int j=0;j<n-i-1;j++)
        {
           cout<<" ";
        }
   cout<<endl;
        }//end of iloop
    }//end of function

   //inverted function

    void pattern91(int n)
    {
        for(int i =0 ;i< n;i++)
        {
            
            for(int j = 0 ;j<i;j++)
        {
            cout<<" ";
        }
            for(int j = 0 ;j<2*n-(2*i+1);j++)
        {
              cout<<"*";
        }
            for(int j = 0 ;j<i;j++)
        {
                cout<<" ";
        }
   cout<<endl;
        }//end of iloop
    }//end of function


};//end of class

int main()
{

    int n;
    cin>>n;
    solution sol;
    sol.pattern9(n);
    sol.pattern91(n);
    return 0;

}