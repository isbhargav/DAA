#include<bits/stdc++.h>
using namespace std;
#define SIZE 32
struct node
{
    int val;
    node* arr[2];
    node()
    {
        val=0;
        arr[0]=arr[1]=NULL;
    }
};
class Trie{
private:
node* head;
public:
Trie(){
    head=new node();
}
void insert(int n)
{
    node* temp=head;
    for (int i=SIZE-1; i>=0; i--)
    {
        bool bit = n & (1<<i);

        if (temp->arr[bit] == NULL)
            temp->arr[bit] = new node();
 
        temp = temp->arr[bit];
    }
    temp->val=n;
}
int query_max(int n)
{
    node* temp=head;
    for (int i=SIZE-1; i>=0; i--)
    {
        bool bit = n & (1<<i);

        if (temp->arr[1-bit] != NULL)
            temp=temp->arr[1-bit];
        
        else if (temp->arr[bit] != NULL)
            temp=temp->arr[bit];
        
    }
    return temp->val;
}
int query_min(int n)
{
    node* temp=head;
    for (int i=SIZE-1; i>=0; i--)
    {
        bool bit = n & (1<<i);

        if (temp->arr[bit] != NULL)
            temp=temp->arr[bit];

        else if (temp->arr[1-bit] != NULL)
            temp=temp->arr[1-bit];
    
    
    }
    return temp->val;
}
};
int main()
{
    Trie t;
    t.insert(0);
    t.insert(1);
    t.insert(2);
    t.insert(3);

   cout<<t.query_max(3);

    return 0;
}