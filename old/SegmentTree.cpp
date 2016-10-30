
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
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

struct Segment
{
    int d;
    int l,h;
    Segment* lf,ri;
    
}
Segment* getTree(Segment* head,int a[],int l,int h)
{
    if(l<h)
    {
        Segment a=getTree(head,a,0,floor((l+h)/2));
        Segment b=getTree(head,a,ceil((l+h)/2,h);
        Segment t=new Segment();
        t->d=min(a->d,b->d);
        t->l=0;
        t->h=h;
        t->lf=a;
        t->ri=b;
    
    }
    if(l==r)

}

int main(){
    int a[]={-1,2,3,1,4,5,1,3};
    Segment *head= NULL;
    head=getTree(head,a,0,sizeof(a)/sizeof(a[0])-1);
    return 0;

}
