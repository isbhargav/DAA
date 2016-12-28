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
vi cut_vertex;
int dfsnum[100];
int dfslow[100];
int low[100];
int parent[100];
int dfscount=0;
int dfsroot=0;
int rootchild=0;
void Cutvertex(int s)
{
    dfsnum[s]=dfslow[s]=dfscount++;
    visited[s]=1;
    for(int i=0;i<(int)graph[s].size();i++)
    {
        ii u=graph[s][i];
        if(visited[u.first]==0)
        {
            parent[u.first]=s;
            
            if(s==dfsroot)
                rootchild++;
            Cutvertex(u.first);

            if(dfslow[u.first]>=dfsnum[s])
                cut_vertex.push_back(s);
            
            dfslow[s]=min(dfslow[u.first],dfslow[s]);

        
        }
        else if(u.first!=parent[s])
            dfslow[s]=min(dfslow[s],dfsnum[u.first]);
    
    
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
        graph[b].push_back({a,b});
    
    }
    dfsroot=2;
    Cutvertex(dfsroot);
  cout<<endl;
  for(int i=0;i<n;i++)
      cout<<dfsnum[i]<<" "<<dfslow[i]<<endl;
  cout<<endl;
   for(auto x : cut_vertex)
   		cout<<x<<" ";
   		cout<<cut_vertex.size();

	
	return 0;
}
