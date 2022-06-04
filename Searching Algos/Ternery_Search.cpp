//Like binary search but aaray is divided into three parts instead of 2
//Time Complexity: O(log3 n)  note: here base of log is 3
#include<bits/stdc++.h>
using namespace std;


int ternery_search(int arr[], int l, int h, int key)
{
    if(h>=l)
    {
        //first partition
        int mid1 = l + (h-l)/3;
        //second partition
        int mid2 = mid1 + (h-l)/3;

        if(arr[mid1] == key)
        {
            return mid1;
        }
        if(arr[mid2] == key)
        {
            return mid2;
        }

        if(key < arr[mid1])
        {
            return ternery_search(arr, l, mid1-1, key);
        }

        if(key > arr[mid2])
        {
            return ternery_search(arr, mid2+1, h, key);
        }

        return ternery_search(arr, mid1+1, mid2-1, key);
    }

    return -1;

}

int main()
{
    int arr[10] = {1,5,5,7,9,51,62,73,84,95};
    int index = ternery_search(arr, 0,9,95 );
    cout<<"Index: "<<index<<endl;
}