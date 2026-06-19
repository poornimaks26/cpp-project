#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Sorting
{
  public:

  int selection_sort(int arr[],int n)
  {
    
    for(int i=0;i<n-1;i++)
    {
        int minindex = i ;
        for(int j=i+1;j<=n;j++)
        {
            if(arr[j]<arr[minindex])
            {
              minindex = j;  
            }
        }
        int temp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp;
    }

  }

  int bubble_sort(int arr[],int x)
  {
    for(int i=x-1;i>=1;i--)
    {
      for(int j=0;j<=i;j++)
      {
        if(arr[j]>arr[j+1])
        {
          int temp = arr[j+1];
          arr[j+1] = arr[j];
          arr[j] = temp;
        }
      }
    }
  }
  
};

int main()
{
    Sorting s,s1;


  int n;
  cout<<"Enter the number of elements in the array: ";
  cin>> n;

  int arr[n];

  for(int i=0;i<n;i++)

{
    cin>>arr[i];
}

 s.bubble_sort(arr,n);
 cout<<"sorted arrey:";

   for(int i=0;i<n;i++)

{
    cout<<arr[i] <<" ";
}
 return 0;
}