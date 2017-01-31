#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,int> si;
typedef pair<int,ii> iii;
typedef vector <si> vsi;
typedef vector <ii> vii;
typedef vector <int> vi;
typedef vector <char> vc;
typedef vector <string> vs;

struct Items
{

    int value;
    int weight;
};

int fractionalKnapsack(int W,vector<Items> &arr)
{
    sort(arr.begin(),arr.end(),[](Items a,Items b){return (a.value/a.weight)<(b.value/b.weight);});
    int sum=0;
    float val=0;
    Items x;
    
    while(sum<W)
    {
        x=arr.back();
        arr.pop_back();
        val+=x.value;
        sum+=x.weight;

    }
    if(sum>W)
    {
        val-=x.value;
        sum-=x.weight;
        val+=(x.value*(W-sum)/x.weight);
    }
    return val;

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int W = 50;   //    Weight of knapsack
        vector<Items> arr= {{60, 10}, {100, 20}, {120, 30}};
         
            int n = sizeof(arr) / sizeof(arr[0]);
             
                cout << "Maximum value we can obtain = "<< fractionalKnapsack(W, arr);
	return 0;
}
