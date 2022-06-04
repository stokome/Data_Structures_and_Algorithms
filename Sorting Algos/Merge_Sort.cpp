//Merge Sort is based on Divide and Conquor Algo
//It divides array into two halves then merges the two halfs after sorting them
//Time Complexity = O(nlogn)
//Merge Sort is uefull in sorting linked list in O(nlogn) time


//Drawbacks-> 1. Slower than other sorting algos for smaller tasks
        //    2.Merge Sort requires additional memory of O(n) for tetmp array
        //    3.It goes through whole process even if array is sorted



#include<bits/stdc++.h>
using namespace std;

//function to merge 

void merge(int arr[], int left, int mid, int right )
{
    int a,b,c;
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    //making two temp arrays
    int leftarr[subArrayOne], rightarr[subArrayTwo];

    //filling temp arrays 

    for(int i=0;i<subArrayOne;i++)
    {
        leftarr[i] = arr[left + i];
    }

    for(int i=0;i<subArrayTwo;i++)
    {
        rightarr[i] = arr[mid +1 + i];
    }
    //filling orignal array in sorted order
    a=0;b=0;c=left;
    while(a < subArrayOne and b < subArrayTwo )
    {
        if(leftarr[a]<=rightarr[b])
        {
            arr[c] = leftarr[a];
            a++;
        }else
        {
            arr[c] = rightarr[b];
            b++;
        }

        c++;
    }
    //if leftsubaaray is left
    while(a<subArrayOne)
    {
        arr[c] = leftarr[a];
        a++;
        c++; 
    }    
    //if right subarray is left
    while(b<subArrayTwo)
    {
        arr[c] = rightarr[b];
        b++;
        c++;
    }
}

//Merge Sort Algo

void merge_sort(int arr[], int l, int r)
{
    if(l<r)
    {
        int mid = l + (r-l)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r); 
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
    merge_sort(arr, 0,9);
    print_arr(arr, 10);
    return 0;
}