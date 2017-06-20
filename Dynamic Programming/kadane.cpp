#include<bits/stdc++.h>
using namespace std;
int main()
{
     int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = kadane(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}