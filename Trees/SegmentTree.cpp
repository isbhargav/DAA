
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
#define N 1000000

ll tree[N];
ll lazy[N];
ll data[N];


void buildtree(int node,int start,int end)
{
    if(start==end)
    { 
        tree[node]=data[start];
        return;
    
    }
    else
    {
        int mid=(end-start)/2;
        buildtree(2*node,start,mid);
        buildtree(2*node+1,mid+1,end);

        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

void update(int node,int start,int end,int l,int r,int val)
{
   
 
    if(lazy[node]!=0)
    {
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    
    }

     if(start>end || start>r || end<l)
        return;

    if(start>=l && end<=r)
    {
        tree[node]+=(end-start+1)*val;
        if(start!=end)
        {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return;
    }

    int mid=(end-start)/2;
    update(2*node,start,mid,l,r,val);
    update(2*node+1,mid+1,end,l,r,val);

    tree[node]=tree[2*node]+tree[2*node+1];



}

ll query(int node,int start,int end,int l,int r)
{
   if(start>end || start>r || end<l)  
        return 0;

   if(lazy[node]!=0)
   {
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        
        }
        lazy[node]=0;
   
   }
   if(start>=l && end<=r)
   {
       return tree[node];
   
   }

   int mid=(end-start)/2;
   ll s1=query(2*node,start,mid,l,r);
   ll s2=query(2*node+1,mid+1,end,l,r);
    
   return s1+s2;

}

int main()
{
//	std::ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>data[i];
    buildtree(1,0,n-1);
    
    for(int i=0;i<=2*n-1;i++)
        cout<<tree[i]<<" ";
   cout<<endl; 
    cout<<query(1,0,n-1,0,1)<<endl;

    cout<<query(1,0,n-1,1,2)<<endl;
    cout<<query(1,0,n-1,2,2)<<endl;
    update(1,0,n-1,0,2,1);
    //call buildtree(1,0,n-1);
    cout<<query(1,0,n-1,0,1)<<endl;
    cout<<query(1,0,n-1,1,2)<<endl;
    cout<<query(1,0,n-1,2,2)<<endl;
    //call update(1,0,n-1,l,r,val)
    //call query(1,0,n-1,l,r)
	
	return 0;
}
