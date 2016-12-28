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

struct Edge
{
    int u,v,w;
    Edge(int a,int b,int c)
    {
        u=a;
        v=b;
        w=c;
    }
};
class Set
{   
    
    vi rank;
    vi parent;
    public:
    Set(int n)
    {
        parent.resize(n);
        rank.resize(n);

    }
    void MakeSet(int n)
    {
        parent[n]=n;
        rank[n]=0;
    }
    int Find(int n)
    {
        if(n==parent[n])
            return n;
        else
            return Find(parent[n]);
    }
    void Union(int a,int b)
    {
        if(rank[a]>rank[b])
        {
            parent[b]=a;
            rank[a]++;
        }
        else if(rank[b]>rank[a])
        {
            parent[a]=b;
            rank[b]++;
        }
        else
        {
            parent[a]=b;
            rank[a]++;
        }
    }

};

struct cmp
{
    bool operator()(Edge x,Edge y)
    {
        return x.w>y.w;
    
    }
};

vector<vii > graph;


void Kruskal(vector<vii > graph)
{
    
    Set s(graph.size());
    vector<Edge> edges;
    for(int i=0;i<(int)graph.size();i++)
    {
        for(int j=0;j<(int)graph[i].size();j++)
        {
            edges.push_back(Edge(i,graph[i][j].first,graph[i][j].second));

        }
    }
    vector<Edge> a;
    for(int i=0;i<(int)graph.size();i++)
    s.MakeSet(i);

    sort(edges.begin(),edges.end(),cmp());
    while(!edges.empty())
    {
        Edge x=edges.back();
        if(s.Find(x.u)!=s.Find(x.v))
        {
            a.push_back(x);
            s.Union(x.u,x.v);
        }
      edges.pop_back(); 
    }

    for(auto x:a)
        cout<<x.u<<" "<<x.v<<" "<<x.w<<endl;


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
    Kruskal(graph);
	
	return 0;
}

