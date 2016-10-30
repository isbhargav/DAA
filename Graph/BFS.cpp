
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
vi BFS_order;

void BFS(int s)
{
    queue<int> q;
    visited[s]=1;
    q.push(s);
    while(!q.empty())
    {
        s=q.front();
        BFS_order.push_back(s);
        q.pop();
        for(int i=0;i<(int)graph[s].size();++i)
        {
            ii p=graph[s][i];
            if(visited[p.first]==0)
            {
                visited[p.first]=1;
                q.push(p.first);
            }
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
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    
    }

   
   

	
	return 0;
}
