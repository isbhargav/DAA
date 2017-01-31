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
#define ROW 4
#define COL 6

void knapsnack();

	int val[] = {0,60, 100, 120};
    int wt[] = {0,10, 20, 30};
	int W[]={0,10,20,30,40,50};
    int  Weight = 50;
    int n = sizeof(val)/sizeof(val[0]);
	int dp[ROW][COL];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	knapsnack();
	for(int i=0;i<ROW;i++)
	{
		
		for(int j=0;j<COL;j++)
		{
			cout<<dp[i][j]<<" ";
			
		}
		cout<<endl;
	}
	return 0;
}

void knapsnack()
{
	for(int i=0;i<ROW;i++)
	{
		
		for(int j=0;j< COL;j++)
		{
			
			if(i==0 || j==0)
				dp[i][j]=0;
			
			else if(W[j]<wt[i])
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			else
				dp[i][j]=max(dp[i][j-1],max(dp[i-1][j],val[i]+dp[i-1][(W[j]-wt[i])/10]));
			
		}
	}
	
}