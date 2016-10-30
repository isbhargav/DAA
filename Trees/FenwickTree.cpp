
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
#define N 100000000

//index starts from 1 so be careful 

ll bit[N];
ll data[N];
int n;
void update(int i,int d)
{
    for(i;i<=n;i+=i&(-i))
    {
        bit[i]+=d;
    }
}
ll query(int i)
{
     ll sum=0;
    for(i;i>0;i-=i&(-i))
    {
        sum+=bit[i];   
    }
    return sum;
}




int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>data[i];
        update(i,data[i]);

    }

    cout<<"sum of first "<<n<<" elements "<<query(n)<<endl;
    cout<<"sum of 1 to 3 "<<query(3)-query(0)<<endl;
    update(2,5);
    cout<<query(3)-query(1)<<endl;


	
	return 0;
}
