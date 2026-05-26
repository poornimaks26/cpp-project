#include <iostream>

using namespace std;

class patterns
{

    public:

    void star1(int N)
    {

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
    }
    void pattern2(int N)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<i;j++)
            {
                cout<<"*";
            }
            cout<<endl;
        } 
    }
    void pattern3(int N)
    {
        for(int i=1;i<=N;i++)
        {
           for(int j=1;j<=i;j++)
           {
            cout<<j<<" ";

           }
           cout<<endl;
        }
    }
    void pattern4(int N)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=i;j++)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
        
    }
    void pattern5(int N)
    {
        for(int i=0;i<=N;i++)
        {
            for(int j=N;j>i;j--)
            {
                cout<<"*";
            }
            cout<<endl;
        }
    }

    void pattern6(int N)
    {
        for(int i=0;i<N;i++){
            for(int j=N;j>i;j--){
                cout<<N-j+1<<" ";

            }
            cout<<endl;
        }


        
    }

void pattern7(int N)
{
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N-i-1;j++)
        {

        cout<<" ";
        }
        for(int j=0;j<2*i+1;j++)
        {
            cout<<"*";
        }
        
        for(int j=0;j<N-i-1;j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}

void pattern8(int N)
{
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {

        cout<<" ";
        }
        for(int j=0;j<2*N-(2*i+1);j++)
        {
            cout<<"*";
        }
        
        for(int j=0;j<i;j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
    
}

void pramid(int n)
{
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<2*i+1;j++){
            cout<<"*";
        }
        
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}
void inverted_pramid(int n)
{
      
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<2*n-(2*i+1);j++){
            cout<<"*";
        }
        
        for(int j=0;j<i;j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}


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
           // cout<<j;

        }
       
        cout<<endl;
    }
}

    };
 int main()
{

    int N = 5;

    patterns p;

    //p.star1(N);

    //p.pattern10(N);

    p.pramid(N);
    p.inverted_pramid(N);

   return 0;
}
