// to sort an array using Quick Sort algorithm
#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>& arr,int low,int high){
    int i=low,j=high,pivot=arr[low];
    while(i<j){
        while(arr[i]<=pivot && i<high)
        i++;
        while(arr[j]>pivot && j>low)
        j--;
        if(i<j)
        swap(arr[i],arr[j]);
    }//end of while loop
    swap(arr[low],arr[j]);
    return(j);
}//end of fn.
void quickSort(vector<int>& arr,int low,int high){
    if(low>=high)
    return;
    int pindex=partition(arr,low,high);
    quickSort(arr,low,pindex-1);
    quickSort(arr,pindex+1,high);
}//end of fn.
int main(){
    int element;
    vector<int> arr;
    cout<<"Enter the elements in the array: ";
    while(cin>>element)
    arr.push_back(element);
    cout<<"The elements in the array are: ";
    for(auto i:arr)
    cout<<i<<" ";
    cout<<endl;
    cout<<"The array after sorting is as follows: ";
    quickSort(arr,0,arr.size()-1);
    for(auto i:arr)
    cout<<i<<" ";
    cout<<endl;
    return(0);
}//end of main