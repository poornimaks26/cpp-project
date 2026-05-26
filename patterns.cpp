#include <iostream>

using namespace std;

/*void pattern(int n)
{
for(int i = 0 ;i<n;i++)
{

    for(int j=0;j<i;j++)
    {

        cout<<"*";

    }
    cout<<endl;

}
}*/

class solution
{
public:

void pattern(int n)
{

for(int i=0;i<n;i++)
{
    for(int j=0;j<=i;j++)
    {

        cout<<"*";
    }
    cout<<endl;
}
}



void pattern2(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j<<"  ";
        }

        cout<<endl;
    }
}

void patterns3(int n)
{
   // cout<<"I loop"<<endl;
    for(int i=1;i<=n;i++)
    {
         
        for(int j = i;j<=n;j++)
        {
            
            cout<<j<<" ";
           // cout<<"J loop"<<endl;
        }
        cout<<endl;
    }
}
  void patterns4(int n)
{
   // cout<<"I loop"<<endl;n
    for(int i=1;i<=n;i++)
    {
         
        for(int j = n;j>=i;j--)
        {
            
            cout<<"*";
           // cout<<"J loop"<<endl;
        }
        cout<<endl;
    }
}


};

int main()
{

    solution sol;

    int n;

    cin>>n;

    //sol.pattern(n);

    sol.patterns4(n);

    return 0;
}

