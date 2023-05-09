//to sort an array using the merge sort algorithm
#include<bits/stdc++.h>
using namespace std;
void merging(vector<int>& arr,int low,int mid,int high){
    vector<int> temp;
    int left=low,right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right])
        temp.push_back(arr[left++]);
        else
        temp.push_back(arr[right++]);
    }
    while(left<=mid)
    temp.push_back(arr[left++]);
    while(right<=high)
    temp.push_back(arr[right++]);
    for(int i=low;i<=high;i++)
    arr[i]=temp[i-low];
}//end of fn.
void mergeSort(vector<int>& arr,int low,int high){
    if(low>=high)
    return;
    int mid=low+(high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merging(arr,low,mid,high);
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
    mergeSort(arr,0,arr.size()-1);
    for(auto i:arr)
    cout<<i<<" ";
    cout<<endl;
    return(0);
}//end of main