#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<limits.h>



using namespace std;
struct cmp
{
    bool operator()(set<int> &l,set<int> &r)
    {
      return l.size()<r.size();
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<set<int> > frds();
        for(i=0;i<=n;i++)
            frds.push_back(set<int>());;
        vector<int> s1,s2;
        int i=0;
   

        
        while(m--)
        {
            
            int a,b;
            cin>>a>>b;
            frds[a].insert(b);
            frds[b].insert(a);
        }
        auto it=min_element(frds.begin()+1,frds.end(),cmp);
        int x=it-frds.begin();
        int min=INT_MAX;
        for(int i=1;i<=n;++i)
           { 
               if(includes(frds[i].begin(),frds[i].end(),frds[x].begin(),frds[x].end()))
                      s1.push_back(i);
                else
                    {
                        s2.push_back(i);
                       
                            if(frds[i].size()<min)
                                min=i;
                       
                    }
           }
           bool flag=true;
        for(auto i2=s2.begin();i2!=s2.end();i2++)
        {
            if(includes(frds[*i2].begin(),frds[*i2].end(),frds[min].begin(),frds[min].end())==false)
            {
                flag=false;
                break;
            }
        }

        if(flag==true)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

        frds.clear();
        s1.clear();
        s2.clear();



    }
}