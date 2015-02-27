#include <iostream>
#include <stdio.h>
using namespace std;

int tree[1000005]={0};
int n;

void update(int idx,int val)
{
	
	while(idx<=n)
	{
		tree[idx]+=val;
		idx+=(idx&-idx);
		
	}
}

int read(int idx)
{
	int sum=0;
	while(idx>0)
	{
		sum+=tree[idx];
		idx-=(idx &-idx);
		
	}
	return sum;
}

int main()
{
	int arr[1000005],q,x,y;
	
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{	
		cin>>arr[i];
		update(i,arr[i]);
	}
	
	
	while(q--)
	{
		
		cin>>x;
		int ans=read(x);
		cout<<ans<<endl;
	}

}