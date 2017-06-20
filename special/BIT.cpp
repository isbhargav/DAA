#include<iostream>
using namespace std;
/*
const int N=1e5;
int n;
int bit[2*N];
void build()
{
    for(int i=n-1;i>0;i--)
    {
        bit[i]=bit[i<<1]+bit[i<<1|1]; //2*i 2i+1
    }
}
void modify(int p,int val)
{
    for(bit[p+=n]=val;p>1;p>>=1)
    {
        bit[p>>1]=bit[p]+bit[p^1];
    }
}
int query(int l,int r)
{
    int res=0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)res+=bit[l++];
        if(r&1)res+=bit[--r];
    }
    return res;
}
*/
const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
  modify(0, 1);
  printf("%d\n", query(3, 5));
  return 0;
}