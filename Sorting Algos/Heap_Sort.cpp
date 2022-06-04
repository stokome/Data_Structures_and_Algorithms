//It is a comparision based sorting algorithm based Binary heapbuh data structure
//Binary Heap is a special complete binary tree where root node is either smaller(min heap) or greater(max heap) than child 
//In heap if parent node is represented by i then left child = 2*i+1 and right child = 2*i+2
//Process of coverting a binary tree into heap is know as heapify

/*
ALGORITHM->
1.Build a max heap from the input data.
2.Largest item is stored at node of the heap. Replace it with the last item of the heap followed by reducing the size of heap by one.
Finally, heapify the root of the tree. Heapified procedure can only be applied to the node if it's children node are already heapified. So 
heapify is always applied in bottom top manner.
3. repeat step 2 while size of heap is greeater than 1.
*/


//Time Complexity = O(logn)     +       O(n)           =       O(nlogn)
//                  (heapify)     (createAndBuildHeap)

//Basically lagest element which is the root of the heap is stored at the end of array and then size of array is decreased by 1.


#include<bits/stdc++.h>
using namespace std;

//function to heapify (a complete binary tree)
void heapify(int arr[], int n, int i)
{
    int largest = i; //assuming root of subtree which is ith position in array has largest value in subtree
    int l = 2*i + 1; //left child of subtress
    int r = 2*i + 2;//right child of subtree
    
    //if left child is greater than the node
    if(l<n and arr[l] > arr[largest])
    {
        largest = l;
    }

    //if right child is greater than the node
    if(r<n and arr[r] > arr[largest])
    {
        largest = r;
    }

    //if root of subtree is not largest in the given subtree
    if(largest != i)
    {
        swap(arr[i], arr[largest]);//swap root and largest child
        heapify(arr, n , largest);// heapify the subtree of the swapped element
    }
}


//HEAP SORT ALGORITHM
void heap_sort(int arr[], int n)
{
    //heapify the imaginary complete binary tree made from the input array 
    for(int i = (n-1)/2; i>=0; i--)
    {
        heapify(arr, n , i);
    }

    for(int i = n-1; i>0; i--)
    {
        swap(arr[0], arr[i]); //swapping root and last element of the array
        heapify(arr, i, 0); //heapify the new tree
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
    heap_sort(arr, 10);
    print_arr(arr, 10);
    return 0;
}