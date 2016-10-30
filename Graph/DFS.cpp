
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

vector<vii > graph;
vi visited;
vi DFS_order;
void DFS(int s)
{
    visited[s]=1;
    DFS_order.push_back(s);

    for(int j=0;j<(int)graph[s].size();++j)
    {
        ii p=graph[s][j];
        if(visited[p.first]==0)
        {
            
            DFS(p.first);
        }
    }

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int n;
    cin>>n;
    graph.resize(n);
    visited.resize(n,0);

    int e;
    cin>>e;
    while(e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        graph[a].push_back({b,w});
    
    }
   
   

	
	return 0;
}
