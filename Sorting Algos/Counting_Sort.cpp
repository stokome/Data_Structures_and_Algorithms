// Counting Sort is based on the keys between specific ranges
// It is a counting based sorting algorithm that counts disinct key values like hashing
// Counting Sort is effective when range is not greater than number of objects to be sorted.
//Counting Sort si uses partital hashing.

/* Steps-
1.Create a count array equal to max_element+1 = {0} (all elements being 0)
2.Increment each element by 1 in count array if index of count array found in orignal array
3.Find cummulative sum in count array
4.Find the correct position of each element by subtracting 1 from cummulative count and placing in new array
*/

//Time Complexity = O(n+k) where k is the range of input


#include<bits/stdc++.h>
using namespace std;
#define RANGE 255

void count_sort(char arr[])
{
    //Output array
    char output[strlen(arr)];

    //count arr and initialize all its element to zero
    int count[RANGE + 1] = {0};
    int i;

    //store the count iof eac character
    for(i = 0; arr[i]; i++)
    {
        ++count[arr[i]];
    }

    //cumulating the count of the element sint he count array
    for(i = 1; i<= RANGE; i++)
    {
        count[i] += count[i-1];
    }

    //build the output character array
    for(i = 0; arr[i]; ++i)
    {
        output[count[arr[i]]-1] = arr[i];//finding position of element from count to output array
        --count[arr[i]];//decrease count of element in count array 
    }

    //copying elements from out to initial array
    for(i = 0; arr[i]; i++)
    {
        arr[i] = output[i];
    }
}

//The above algo cannot sort negative elements as we do not have -ve array indice
void count_sort_negativeNumbers(vector<int>& arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max-min + 1;

    //creating output and count array
    vector<int> count(range), output(arr.size());


    //incrementing the count array
    for(int i = 0; i < arr.size(); i++)
    {
        count[arr[i] - min]++;
    }

    //cumulating the count of the count array
    for (int i = 1; i < count.size(); i++)
    {
        count[i] += count[i-1];
    }

    //build the output array
    for(int i = arr.size()-1; i >= 0; i--)
    {
        output[count[arr[i]-min]-1] = arr[i];
        count[arr[i]-min]--;
    }

    //Copying the contents of the output array in the orignal array
    for(int i = 0; i < arr.size(); i++)
    {
        arr[i]  =  output[i];
    }
}

void printArray(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}
  
int main()
{
    char arry[] = "geeksforgeeks";
    cout<<arry<<endl;
    count_sort(arry);
    cout<< arry<<endl<<endl;
    vector<int> arr = { -5, -10, 0, -3, 8, 5, -1, 10 };
    printArray(arr);
    count_sort_negativeNumbers(arr);
    printArray(arr);
    return 0;
}