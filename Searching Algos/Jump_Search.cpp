//Similiar to Binary Search  this algo is for sorted array. 
//checks elements of array after each interval of m indexes until array[xm]>key.
//after this performs linear search for (x-1)m to xm.
//best value of m = sqrt(n)  where n = no of elemnets in array.
//Time Complexity = O(sqrt(n))
//Time Complexity -> Linear Search> Jump Search > Binary Search
//In a system where binary search is costly, we use Jump Search.
#include<bits/stdc++.h>
using namespace std;

int jump_search(int arr[], int n, int key)
{
    //block size to be jumped
    int step = sqrt(n);

    int prev = 0;
    //finding largest step and previous step between which key would lie
    while(arr[min(step, n)-1]<key)//compairing key with array data at multiple of sqrt(n)
    {
        prev = step;//storing value of previous step
        step+=sqrt(n);//calculation of current step
        //if we reach end of array
        if(prev>=n)
        {
            return -1;
        }
    }
    //if we reach end of array
    while(arr[prev]<key)
    {
        prev++;
        if(prev == min(n, step))
        {
            return -1;
        }
    }
    //if we finf the element
    if(arr[prev]==key)
    {
        return prev;
    }

    return -1;
}


int main()
{
    int arr[10] = {1,5,5,7,9,51,62,73,84,95};
    int index = jump_search(arr, 10,62 );
    cout<<"Index: "<<index<<endl;
}
