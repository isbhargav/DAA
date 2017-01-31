
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

struct cmp
{
    bool operator()(ii &a,ii &b)
    {
        return a.second > b.second;
    }
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

vector<pair<int,int> > a;
/*vi b={1,2,4,6,78,54,76,77};
make_heap(b.begin(),b.end());
cout<<b.front()<<endl;
pop_heap(b.begin(),b.end());
b.pop_back();
cout<<b.front()<<endl;
pop_heap(b.begin(),b.end());
b.pop_back();
cout<<b.front()<<endl;
pop_heap(b.begin(),b.end());
b.pop_back();
cout<<b.front()<<endl;
pop_heap(b.begin(),b.end());
b.pop_back();
cout<<b.front();
*/


a.push_back(make_pair(1,2));
a.push_back(make_pair(2,4));
a.push_back(make_pair(6,1));
a.push_back(make_pair(32,65));
a.push_back(make_pair(78,99));
a.push_back(make_pair(45,23));
//a.push_back(make_pair(-1,-1));

	make_heap(a.begin(),a.end(),cmp());
  
    cout<<a.front().first<<" "<<a.front().second<<endl;
   pop_heap(a.begin(),a.end(),cmp());a.pop_back();
   cout<<a.front().first<<" "<<a.front().second;
   
   pop_heap(a.begin(),a.end(),cmp());a.pop_back();
   int r=65;
   auto itr=find_if(a.begin(),a.end(),[r](ii &x){return x.second==r;});
           if(itr!=a.end())
            itr->second=3;
    make_heap(a.begin(),a.end(),cmp());
   cout<<endl; 
   cout<<a.front().first<<" "<<a.front().second;
    
    return 0;
}
