//Check current element with previous element and if its smaller then the element is compared with all elemnets behind it until 
//another element with value smaller than itself is found or starting of array is reached.\
//Time Complexity = O(n^2)
//Algorithm PAradigm = Incremental Approch
//USe-> small dataset or only few elements are needed to be sorted

#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        //check if prev element is greater than next element
        int key = arr[i];
        //shifting elements to right 
        while(i>=1 and key < arr[i-1])
        {
            arr[i] = arr[i-1];
            i = i-1;
        }
        //placing key at right place
        arr[i] = key;
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
    insertion_sort(arr, 10);
    print_arr(arr, 10);
    return 0;
}