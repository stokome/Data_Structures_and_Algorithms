//Radix Sort- Here we sort digits from least significant digit to most significant digit of a number
//Radix Sort uses other sorting algos as subtroutine such as counting sort and bucket sort.
//Time Complexity = O(n)
#include <iostream>
using namespace std;


//find max element in the array
int get_max(int arr[], int n)
{
    int mx = arr[0];
    for(int i = 0; i<n; i++)
    {
        if(arr[i] > mx)
        {
            mx = arr[i];
        }
    }
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix_sort(int arr[] , int n)
{
    //find maximum nuber int the array
    int m = get_max(arr, n);

    //// Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for(int exp = 1; m/exp > 0; exp*=10)
    {
        countSort(arr, n , exp);
    }
}


void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    cout<<endl;
}
 
// Driver Code
int main()
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    // Function Call
    radix_sort(arr, n);
    print(arr, n);
    return 0;
}