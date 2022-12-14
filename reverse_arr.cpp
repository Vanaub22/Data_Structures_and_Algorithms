//to reverse an array
#include<iostream>
using namespace std;
void reverse_arr(int*,int);
int main()
{
    int size,arr[100];
    cout<<"Enter the number of elements in the array:";
    cin>>size;
    cout<<"Enter the elements of the array separated by spaces: ";
    for(int i=0;i<size;i++)
    cin>>arr[i];
    reverse_arr(arr,size);
    return 0;
}//end of main
void reverse_arr(int* arr,int size){
    int start=0,end=size-1;
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }//end of while loop
    cout<<"The reversed array is as follows: ";
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}//end of fn.