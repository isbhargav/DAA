
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
vi indegree;
vi topological_order;
void kahn()
{
    queue<int> q;
    for(int i=0;i<indegree.size();++i)
        if(indegree[i]==0)
            q.push(i);

    while(!q.empty())
    {
        int s=q.front();
        topological_order.push_back(s);
        q.pop();
        for(int i=0;i<graph[s].size();++i)
        {
            ii p=graph[s][i];
            if(--indegree[p.first]==0)
                q.push(p.first);
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
    indegree.resize(n,0);

    int e;
    cin>>e;
    while(e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        graph[a].push_back({b,w});
        indegree[b]++;
    }
   kahn();
   for(auto x : topological_order)
       cout<<x<<" ";
   

	
	return 0;
}
