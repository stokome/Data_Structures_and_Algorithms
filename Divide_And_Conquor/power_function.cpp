// Create function to find x^n
// Algorithm Paradigm is Divide and Conquor
// algo ->x^n = x^n/2 * x^n/2 (using recusrion or iteration)

#include<bits/stdc++.h>
using namespace std;


int pow(int x, int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n%2==0)
    {
        return pow(x,n/2)*pow(x,n/2);
    }
    else
    {
        return x*pow(x,n/2)*pow(x,n/2);
    }
}
//time complexity of this function is O(n)
//Optimizing the above function by saving the value of pow(x, n/2)

int optimized_pow(int x, int n)
{
    if(n==0)
    {
        return 1;
    }
    int temp = pow(x, n/2); //saving the value in the temp
    if(n%2==0)
    {
        return temp*temp;
    }
    else
    {
        return x*temp*temp;
    }
}

//Now also including the power as negative integer



float neg_pow(float x, int n)
{
    if(n==0)
    {
        return 1;
    }
    float temp = pow(x, n/2); //saving the value in the temp
    if(n%2==0)
    {
        return temp*temp;
    }
    else
    {
        if(n>0)
        {
            return x*temp*temp;
        }else
        {
            return (temp * temp)/x;
        }
    }
}



int main()
{
    cout<<pow(4,6)<<endl;
    cout<<optimized_pow(4,4)<<endl;
    cout<<neg_pow(25,-1)<<endl;
}