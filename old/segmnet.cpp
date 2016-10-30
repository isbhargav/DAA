
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
struct node
{
    int d;
    int l,h;
    struct node *lptr,*rptr;

};
typedef struct node node;
int min(int a,int b){return a<b?a:b;}
int RMQ(node* head, int qs,int  qe) 
{
       if (head->l>qs && head->h<qe) //total overlap 
                   return head->d;
       else if  ((head->l<qs && head->h<qs) ||(head->l>qe && head->h>qe)) //no overlap return infinite
                   return INT_MAX;
       else
                  return min( RMQ(head->lptr, qs, qe), RMQ(head->rptr, qs, qe) );
}
node* gettree(int arr[],int l,int u)
{
    if(l==u)
    {
        node* t=new node();
        t->d=arr[l];
        t->lptr=NULL;t->rptr=NULL;
        t->l=l;t->h=l;
        return t;
    }
    int mid=(int)floor((l+u)/2);
    node *a=gettree(arr,l,mid);
    node* b=gettree(arr,mid+1,u);
    node* temp=new node();
    temp->lptr=a;
    temp->rptr=b;
    temp->d=min(a->d,b->d);
    temp->l=l;
    temp->h=u;
    return temp;

}
main()
{
    node* head=NULL;
    int arr[]={2,5,1,4,-1,3};
    head=gettree(arr,0,5);
    cout<<head->d;
    cout<<endl;
    cout<<RMQ(head,1,4);
}
