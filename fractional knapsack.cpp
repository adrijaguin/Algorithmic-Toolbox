#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct item
{
   double value, weight; 

};

bool cmp (struct item a, struct item b)
{
    long double r1= ((double)a.value/a.weight);
    long double r2= ((double)b.value/b.weight);
    return r1>r2;
}

long double maxval(long double w, struct item arr[], int n)
{
    long double current=0, final=0;
    sort(arr, arr + n, cmp);
    for (int i=0; i<n; ++i)
    {
        if (current + arr[i].weight <= w)
        {
            current+= arr[i].weight;
            final+= arr[i].value;
        }
        else
        {
            long double remain= w- current;
            final+= ((arr[i].value)/(arr[i].weight))*remain;
            break;
        }
    }
    cout << setprecision(10) << final << endl;
}

int main ()
{
    long double w;
    int n;
    cin >> n >> w;
    item arr[100];
    for (int i=0; i<n; ++i)
    {
        cin >> arr[i].value >> arr[i].weight;
    }
   
    maxval(w, arr, n);
}
