
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
vi topological_order;
void tarjans(int s)
{
    visited[s]=1;

    for(int j=0;j<(int)graph[s].size();++j)
    {
        ii p=graph[s][j];
        if(visited[p.first]==0)
        {
            
            tarjans(p.first);
        }
    }
    topological_order.push_back(s);
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
    tarjans(0);
    reverse(topological_order.begin(),topological_order.end());

   for(auto x : topological_order)
       cout<<x<<" ";
   

	
	return 0;
}
