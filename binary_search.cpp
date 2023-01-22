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
            return (1);
        else if (arr[mid] < key)
            start = mid;
        else
            end = key;
    } // end of while loop
    return (0);
} // end of fn.
int main()
{
    int size, key;
    cout << "Enter the size of the array:";
    cin >> size;
    cout << endl;
    int arr[size];
    cout << "Enter the elements of the array separated by spaces:" << endl;
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "Enter the key value to be searched:";
    cin >> key;
    cout << endl;
    if (binarySearch(arr, size, key) == 0)
        cout << "The key value is not present in the array" << endl;
    else
        cout << "The key value is present in the array" << endl;
}
