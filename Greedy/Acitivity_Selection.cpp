
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

void printMaxActivities(vii &activity)
{
    //1.sort the array acording to there ending time
    sort(activity.begin(),activity.end(),[](ii a,ii b){return a.second > b.second;});

    //2.

    int prev=-1;
    int count=0;
    while(!activity.empty())
    {
        ii next=activity.back();
        activity.pop_back();
        if(prev < next.first)
        {
            count++;
            prev=next.second;
        }
        
    }
    cout<<"MAX number of activities possible :"<<count;
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    vii actvity={{1,2} ,{3,4} ,{0,6} ,{5,7} ,{8,9} ,{5,9}};
    printMaxActivities(actvity);
	
	return 0;
}
