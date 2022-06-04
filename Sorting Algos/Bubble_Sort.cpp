// Adjacent elements are swapped until whole array is sorted
//Time Complexity  = O(n^2)

#include<bits/stdc++.h>
using namespace std;


void bubble_sort(int arr[], int n)
{
    bool stop;
    for(int i=0; i<n; i++)
    {
        stop = true;
        for(int j=0; j<n-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                stop = false;
            }
        }

        if(stop == true)
        {
            break;
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
    bubble_sort(arr, 10);
    print_arr(arr, 10);
    return 0;
}