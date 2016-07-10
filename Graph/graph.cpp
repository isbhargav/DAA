#include<iostream>
#include<vector>
#include<unordered_map>
struct Edge
{
				char a;
				char b;
				int w;
				Edge(char x, char y,int z)
				{
								a=x;
								b=y;
								w=z;
				}
				Edge(){}

};
class graph
{
				public:
								vector<char> vertices;
								vector<Edge> edges;
								
};

