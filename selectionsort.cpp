#include<iostream>
#include <vector>
using namespace std;

class selection
{
 public:
 
 vector<int> selectionsort(vector<int> arr)
 {
    int n = arr.size();

    for(int i=0;i<=n-1;i++)
    {
        int min =i;
        for(int j=i;j<=n-1;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }

        }
        swap(arr[min],arr[i]);
    }
    return arr;
 }

 vector<int> bubblesort(vector<int>& arr)
 {
int n= arr.size();

    for(int i=n-1;i>=1;i--)
{
   for(int j=0;j<=i-1;j++)
   {
    if(arr[j]>arr[j+1])
    {
        swap(arr[j],arr[j+1]);
    }
   }
}
return arr;
 }
   
};

int main()
{
 selection s;

/* selection sort
 int  n;
 cout<<"Enter the number of elements in the array: ";
 cin>>n;
 vector<int> nums(n);
 for(int i=0;i<n;i++)
 {
    cin>>nums[i];
 }
 s.selectionsort(nums);    
cout<<"sorted arrey:";
 for(int x: nums)
 {
  cout<<x<<" ";
 }
  */ 

 /* Bubble sort */

 int n;
cout<<"Enter the number of elements in the array: ";
 cin>>n;

 vector<int> b(n);

 for(int i=0;i<n;i++)
 {
   cin>>b[i];
 }

 s.bubblesort(b);
 
cout<<"sorted arrey:";
 for(int x: b)
 {
    cout<<x<<" ";
 }

 return 0;
}