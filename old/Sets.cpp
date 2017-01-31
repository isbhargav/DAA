#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<unordered_set>
#include<unordered_map>
#include<limits>

#define INT_MAX 999
using namespace std;
struct Edge
{
	char a;
	char b;
	int w;
	Edge(char x, char y, int z)
	{
		a = x;
		b = y;
		w = z;
	}


};


class graph
{
public:
	vector<char> vertices;

	vector<Edge> edges;
	vector<Edge> adjedges(char s);
	vector<char> BFS(char s);
	vector<char> DFS(char s);
	unordered_map<char, int> Dijkastras(char s);

};
vector<char> graph::BFS(char s)
{
	unordered_map<char, bool> visited;
	for (auto x : vertices)
		visited[x] = false;

	vector<char> e;
	e.push_back(s);
	visited[s] = true;
	auto it = e.begin();
	while (it != e.end())
	{
		s = *it;
		vector<Edge> a = adjedges(s);
		for (auto x : a)
		{
			if (!visited[x.b])
			{
				e.push_back(x.b);
				visited[x.b] = true;
			}

		}

		it++;
	}

	return(vector<char>(e.begin(), e.end()));

}
vector<Edge> graph::adjedges(char s)
{
	vector<Edge> res;
	for (auto x : edges)
	{
		if (x.a == s)
			res.push_back(x);
	}
	return res;
}

vector<char> graph::DFS(char s)
{
	unordered_map<char, bool> visited;
	vector<char> res;

	for (auto x : vertices)
		visited[x] = false;


	visited[s] = true;

	stack<char> st;
	st.push(s);
	while (!st.empty())
	{
		res.push_back(s = st.top());
		st.pop();
		vector<Edge> a = adjedges(s);
		for (auto x : a)
		{
			if (visited[x.b] == false)
			{
				visited[x.b] = true;
				st.push(x.b);
			}

		}

	}
	return res;

}
unordered_map<char, int> graph::Dijkastras(char s)
{
	unordered_map<char, char> path;
	unordered_map<char, int> dist;
	for (auto a : vertices)
	{
		dist[a] = INT_MAX;
		path[a] = '-';
	}
	path[s] = s;
	dist[s] = 0;
	deque<char> q;
	q.push_back(s);
	while (!q.empty())
	{

		s = q.front();
		q.pop_front();
		vector<Edge> n = adjedges(s);
		for (auto x : n)
		{
			if (find(q.begin(), q.end(), x.b) == q.end())
				q.push_back(x.b);
			dist[x.b] = dist[x.a] + x.w;
			path[x.b] = x.a;
			vector<Edge> m = adjedges(x.b);
			for (auto y : m)
			{
				int d = dist[y.a] + y.w;
				if (d<dist[y.b])
				{

					dist[y.b] = d;
					path[y.b] = y.a;
				}


			}

		}

	}


	return dist;


}
int main()
{
	graph g;
	char a[] = { 'a','b','c','d' };
	g.vertices = vector<char>(a, a + sizeof(a) / sizeof(a[0]));
	g.edges.push_back(Edge('a', 'w', 3));
	g.edges.push_back(Edge('a', 'c', 4));
	g.edges.push_back(Edge('b', 'd', 2));
	g.edges.push_back(Edge('d', 'a', 1));
	g.edges.push_back(Edge('c', 'b', 1));

	//vector<char> res=g.DFS('a');
	//for(auto x: res)
	//           cout<<x<<" "<<endl;

	unordered_map<char, int> m = g.Dijkastras('a');
	//		for(auto x= m.begin();x!=m.end();++x)
	//					cout<<m.first<<":"<<m.second;
	for (auto x : g.vertices)
		cout << x << ":" << m[x];

	cin.get();
	return 0;
}
