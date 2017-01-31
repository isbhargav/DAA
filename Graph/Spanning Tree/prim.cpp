
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
struct cmp
{
    bool operator()(ii &a,ii &b)
    {
        return a.second > b.second;
    }
};
void prim(vector<vii > graph,int s)
{
    vii points;
    vi visited;
    vi parent;
    for(int i=0;i<(int)graph.size();i++)
        {
            points.push_back(make_pair(i,INT_MAX));
            visited.push_back(0);
            parent.push_back(-1);
        }
    points[s].second=0;
    visited[s]=1;
    parent[s]=s;
    make_heap(points.begin(),points.end(),cmp());

    while(!points.empty())
    {
        //pop  the min ele
        ii x=points.front();
        pop_heap(points.begin() , points.end(),cmp());
        points.pop_back();
        visited[x.first]=1;
        //for all its adj vertices
        for(int i=0;i<(int)graph[x.first].size();i++)
        {
            ii y=graph[x.first][i];
            
            if(visited[y.first]==0)
            {
                
                auto itr=find_if(points.begin(),points.end(),[x](ii &a){ return a.first==x.first;});
                if(itr!=points.end())
                {
                    if((*itr).second > x.second)
                    {
                        itr->second=x.second;
                        parent[itr->first]=x.first;
                    }
                }
            }
        }
            make_heap(points.begin(),points.end(),cmp());
    }

    for(int i=0;i<(int)parent.size();i++)
        cout<<i<<" "<<parent[i]<<endl; 
    

}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin>>n;
    graph.resize(n);

    int e;
    cin>>e;
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    
    }
    cout<<"MST contains ";
    prim(graph,0);
	
	return 0;
}

