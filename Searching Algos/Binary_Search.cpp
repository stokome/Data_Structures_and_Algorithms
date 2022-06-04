// Binary Search only works on the sorted array or respective data structure
// In We reduce the size of searchable portion from middle by finding if middle element is larger or smaller than key
// Time Complexity = O(log(n))

#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int l, int r, int key)
{
    if(r>=l)
    {
        //find middle element of array
      //int middle = (l+r)/2; --->>>  it fails for larger values of int variables low and high.
      //Specifically, it fails if the sum of low and high is greater than the maximum positive int value(2^31 – 1 ).

        int middle = l + (r-l)/2; // so we use this way
        //if middle elements = key
        if(arr[middle] == key)
        {
            return middle;
        }
        //if middle element > key
        if(arr[middle] > key )
        {
            return binary_search(arr, l, middle-1, key);
        }
        //if middle elment < key
        return binary_search(arr, middle+1, r, key);
    }

    return -1;
        
}

int main()
{
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int index = binary_search(arr, 0, 9, 9);
    cout<<index<<endl;
}