// Linear Seach just simply compares each element of the the array to the key 
// time Complexity = O(n)

#include<bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int n, int key)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    int index = linear_search(arr, 10, 5);
    cout<<"Index: "<<index<<endl;
}