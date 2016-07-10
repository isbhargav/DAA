#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<queue>
#include<cmath>
#include<limits>
#include<unordered_map>

using namespace std;
class disjoint_sets
{
	unordered_map<char,char> parent;
	unordered_map<char, int> rank;
public:
	disjoint_sets()
	{
		char a[]={'a','b','c','d','e'};
		for (auto x : a)
		{
			parent[x] = x;
			rank[x] = 0;
		}
	}
	char find(char a)
	{
		if (parent[a] == a)
		{
			return a;
		}
		else
		{
			return find(parent[a]);
		}
	}
	void UNION(char a, char b)
	{
		if (rank[a] > rank[b])
		{
			parent[b] = a;
			
		}
		else if (rank[b] > rank[a])
		{
			parent[a] = b;
		}
		else
		{
			parent[b] = a;
			parent[a]++;
		}
	}
};
struct cmp
{
	bool operator()(pair<int, int> &lhs, pair<int, int> &rhs)
	{
		return lhs.second > rhs.second; 
	}
};
int main()
{
	priority_queue < pair<int, int>, vector<pair<int, int> >, cmp > pq;
	pq.push(make_pair(0, 2));
	pq.push(make_pair(1, 1));
	pq.push(make_pair(2, 99));
	pq.push(make_pair(3, 8));
	while (!pq.empty())
	{
		cout << (pq.top()).first << " " << (pq.top()).second;
		pq.pop();
		cout << endl;
	}
	cin.get();
	return 0;
}
