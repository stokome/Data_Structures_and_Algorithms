//Its is an improved version of Binary Search
//Interpolation Search goes to different location according to value of the key to be searched
//Elements of array are linearly distributed
//To find the position to be searched it uses a formula-> pos = low + [ (Key-arr[low])*(high-low) / (arr[high]-arr[Low]) ]
//Time Complexity: O(log2(log2 n))   note: here both 2 is base of log
#include<bits/stdc++.h>
using namespace std;

int interpolation_search(int arr[], int low, int high, int key)
{
    if(high>=low)
    {
        //finding postion of index closuer to key
        int pos = low +  ((key-arr[low])*(high-low) / (arr[high]-arr[low]));

        if(arr[pos] == key)
        {
            return pos;
        }
        if(arr[pos]>key)
        {
            return interpolation_search(arr, low, pos-1,key);
        }

        return interpolation_search(arr, pos+1, high, key);
    }

    return -1;
}


int main()
{
    int arr[10] = {1,5,5,7,9,51,62,73,84,95};
    int index = interpolation_search(arr, 0,9, 52);
    cout<<"Index :"<<index<<endl;
}