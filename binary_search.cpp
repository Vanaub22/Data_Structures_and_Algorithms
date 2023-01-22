// Recursive Binary Search
#include <iostream>
using namespace std;
int binarySearch(int *arr, int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2; // using optimized approach to avoid overflow
    while (start <= end)
    {
        if (arr[mid] == key)
            return (mid);
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
        mid = start + (end - start) / 2;
    }            // end of while loop
    return (-1); // element not found
} // end of fn.
int main()
{
    int size, key, index;
    cout << "Enter the size of the array:";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array separated by spaces:";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "Enter the key value to be searched:";
    cin >> key;
    index = binarySearch(arr, size, key);
    if (index == -1)
        cout << "The key value is not present in the array" << endl;
    else
        cout << "The key value " << key << " is present in the array at index position:" << index << endl;
} // end of main
