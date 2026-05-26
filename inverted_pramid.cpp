#include <iostream>

using namespace std;


class pyramid
{

    public:
   /* void pattern9(int n){
     //pramid
    for(int i =0;i<n;i++){
     
        //spcae

        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";

        }
        //stars
        for(int j=0;j<2*i+1;j++){
            cout<<"*";
        }

       cout<<endl;
    }


    //inverted pattern
    for(int i=n-1;i>=0;i--)
    {
     //spcae

     //n=5  i = 5-1 to 0 i--
     // i=4 
     //

        for(int j=0;j<n-i-1;j++)
        {

            //i=5 j=5-0-1  j=5
            cout<<" ";

        }
        //
        for(int j=0;j<2*i+1;j++){
            //2*4+1-->9
            cout<<"*";
        }

       cout<<endl;
    }
}
*/
 void pattern10(int n)
 {
for(int i=1;i<=2*n-1;i++)
{
   int stars =i;

   if(i>n) stars=2*n-i;


    for(int j=1;j<=stars;j++)
    {
     cout<<"*";

    }
    cout<<endl;
}

 }
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void pattern10(int n)
{
    
    for(int i=0;i<2*n-1;i++){
        
        int stars=i;
        //cout<<"1st "<<stars<<endl;
        if(i>n) stars=2*n-i;
        //cout<<"2nd "<<stars<<endl;
        
       
        for(int j=0;j<=stars;j++){
            //cout<<"3rd "<<stars<<endl;
            cout<<"*";
        }
       
        cout<<endl;
    }
}




};

int main()
{
int n=5;

pyramid p;

p.pattern10(n);

return 0;
}

