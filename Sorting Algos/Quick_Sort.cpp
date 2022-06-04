//Like merge sort it also follows divide and conquor
//Pick a element in the array as pivot and partition the given array around it
//Pivot can be - 1.first element 2.last element 3.random element 4. median element
//Put all grater lement aftes pivot and lesser elements before pivot
 
 #include<bits/stdc++.h>
 using namespace std;

 //here we choose last element as pivot and place smaller elements before pivot and vice-versa


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low-1;//index that divedes elements on left and right of pivot

    for(int j=low;j<=high-1; j++)
    {
        //if currrent element is smaller than pivot
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quick_sort(int arr[], int low, int high)
{
    if(low<high)
    {
        int p = partition(arr,low,high);
        quick_sort(arr,low, p-1);
        quick_sort(arr, p+1, high);
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
    quick_sort(arr, 0,9);
    print_arr(arr, 10);
    return 0;
}


//Worst CAse of Quick Sort- 
//1.Array are sorted in the same order
//2.Array is sorted in the reverse order
//3.All elements of the array are equal