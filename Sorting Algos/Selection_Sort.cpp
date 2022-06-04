//Iterates across whole array and swaps if arr[left_index] > arr[right_index]
//Time Complexity = O(n^2)
//The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation. 
#include<bits/stdc++.h>
using namespace std;



void selection_sort(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }
}

void print_arr(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[10] = {1,50,51,7,9,5,2,73,4,9};
    print_arr(arr, 10);
    cout<<"\n";
    selection_sort(arr, 10);
    print_arr(arr, 10);
    return 0;
}