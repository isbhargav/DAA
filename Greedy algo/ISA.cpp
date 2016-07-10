#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stack>
#include<deque>
using namespace std;
vector<pair<int,int > > ISA(vector<pair<int,int> >& vec);

int main()
{
    vector<pair<int,int> > vec;

    vec=ISA(vec);
     for(auto x: vec)
     {
        cout<<x.first<<" "<<x.second;
     }

    return 0;
}
vector<pair<int,int > > ISA(vector<pair<int,int> >& vec)
{
    sort(vec.begin(),vec.end(),[](pair<int,int>& lhs,pair<int,int>& rhs)
    {
        return(lhs.second < rhs.second);
    });
    vector<pair<int,int> > s;
    deque<pair<int,int> > d(vec.begin(),vec.end());

    //vector<pair<int,int> > vec_dupli(vec.begin(),vec.end());
    s.push_back(vec.front());
    d.pop_front();
    while(!d.empty())
    {
        for(auto it=d.begin();it!=d.end();)
        {
            if((s.back()).second>it->first)
                it=d.erase(it);
            else
                it++;
        }
        s.push_back(d.front());
        d.pop_front();
    }

    return(s);

}
