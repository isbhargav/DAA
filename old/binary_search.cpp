#include<iostream>
#include<vector>
#include<random>
#include<ctime>

using namespace std;

int binary_search(vector<int> &vec ,int l,int u,int x);
main()
{
			vector<int> vec;
			default_random_engine rg(time(0));
			uniform_int_distribution<int> diceroll(1,100);
			for(int i=0;i<50;i++)
			{
							vec.push_back(diceroll(rg));
			}
				for(auto x : vec)
				cout<<x<<" ";

				cout<<endl;

				if(binary_search(vec,0,vec.size()-1,25)==-1)
								cout<<"not found";
				else
								cout<<"Found at:"<<binary_search(vec,0,vec.size()-1,25);

							

}
int binary_search(vector<int> &vec ,int l,int u,int x)
{
				int mid=(l+u)/2;
				if(u>=l)
				{
				if(vec[mid]==x)
								return mid;
				else if(vec[mid]>x)
								return binary_search(vec,mid+1,u,x);
				else 
								return binary_search(vec,0,mid-1,x);
				}
				return -1;
}
