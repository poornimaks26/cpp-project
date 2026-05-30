#include <iostream>

using namespace std;

void printname(string name)
   {

    cout<<"Name of function :"<<name<<endl;
   }


   void dosomething(int &num)
   {

    cout<<"value of num:\n"<<num<<endl;
    num += 5;

    cout<<"value of num:\n"<<num<<endl;
    num += 5;
 cout<<"value of num:\n"<<num<<endl;
    
   }

   void passbrefernce(string &s)
   {
    s[0] = 't';

    cout<< s << endl;

   }

int main()
{   


int arr1[5];
for(int i = 0;i<=4;i=i+1)
{
 
 

 cin>>arr1[i];
}

cout<<"result of arr"<<i<<" "<<endl;
  /*   int arr[5];

    cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4];
     cout<<"arra list:\n";
    cout<<arr[0]<<endl<<arr[1]<<endl<<arr[3];

    return 0;
  /*  string s = "raj";

    passbrefernce(s);
    cout << s << endl;


     cout<<"pass b value\n";
     
    int num = 10;
     dosomething(num);
     cout<<num; 

    /* cout<<"string:\n ";

    string name;

    cin>>name;

    printname(name);
    /*int arr[5];

    cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4]>>arr[5];

    cout<<arr[4];*/


  /* int arr2d[3][5];

   arr2d[1][2] = 78 ;

   cout<<arr2d[2][3];

   string s = "string";
   int len = s.size();
   s[len-1] = 'z';
   cout<<s[len-1]
   */


  /* for(int i = 2;i<=10;i++)
   {

    cout<<"for loop iteration:"<<i<<endl;
    
   }
    

   int j = 2;

  /* while(j<= 5)
   {
    cout<<"while loop:"<<j<<endl;
    j = j+1;
   }
         */
    /*do
   {
    cout<<"do while:"<<j<<endl;
    j = j+1;
   } while (j<=1);

   cout<<j<<endl;
   */
    return 0;


    //pass b value
   

}


