//DFS in directed graph

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>

using namespace std;
vector<int> v[100];
int visited[100];

void dfs(int src,int n)
{
	stack<int> st;
	st.push(src);
	visited[src]=1;

	while(!st.empty())
	{
		int u=st.top();
		printf("%d ",u);
		st.pop();
		for(int i=0;i<v[u].size();i++)
		{
			int pos=v[u][i];
			if(visited[pos]==-1)
			{
				st.push(pos);
				visited[pos]=1;
			}
		}
	}
}

int main()
{
	int n,e;
	scanf("%d %d",&n,&e);
	for(int i=0;i<e;i++)
	{
		int src,dest;
		scanf("%d %d",&src,&dest);
		v[src].push_back(dest);	
	}
	for(int i=0;i<n;i++)
	{
		visited[i]=-1;
	}

	for(int i=0;i<n;i++)
	{
		if(visited[i]==-1)
		{
			dfs(i,n);
		}
	}
	printf("\n");

}