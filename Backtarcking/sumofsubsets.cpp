#include<iostream>
#define M 4
using namespace std;
int arr[M]={2,3,4,5};
int x[M];
int m=7;
void sumofsubset(int sum,int k,int rem){
    x[k]=1;
    if(sum+arr[k]==m)
    {
        for(int i=0;i<M;i++)
        {
            cout<<x[i]<<"  ";
        }
        cout<<endl;
  //      return;
    }
    else if(sum+arr[k]+arr[k+1]<=m)
        sumofsubset(sum+arr[k],k+1,rem-arr[k]);
    if(sum+rem-arr[k]>=m && sum+arr[k+1]<=m)
    {
        x[k]=0;
        sumofsubset(sum,k+1,rem-arr[k]);
       return;
    }
   x[k]=0;
    
}
int main()
{
    
    sumofsubset(0,0,14);

}