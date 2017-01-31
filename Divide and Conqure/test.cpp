
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



int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
list<list<int> > a;
for(int i=0;i<3;i++)
{   
    a.push_back(list<int>());    
    for(int j=0;j<3;j++)
    {
        a[i].push_back(i*j+1);
    
    }
    
for(int i=0;i<3;i++)
{   
    for(int j=0;j<3;j++)
    {
            cout<<a[i][j]; 
    }
}
    return 0;
}


