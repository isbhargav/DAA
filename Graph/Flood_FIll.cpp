
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

int dr[]={1,1,0,-1,-1,-1,0,1};
int dc[]={0,1,1,1,0,-1,-1,-1};
char grid[1000][1000];
int R,C;

int floodfill(int r,int c,int ch1,char ch2)
{
    if(r<0 || c<0 || r>=R || c>=C)
        return 0;
    if(grid[r][c]!=ch1)
        return 0;

    int ans=1;
    grid[r][c]=ch2;
    for(int i=0;i<8;++i)
    {
        ans+=floodfill(r+dr[i],c+dc[i],ch1,ch2);
    }
    return ans;
    
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>R>>C;
	
	return 0;
}
