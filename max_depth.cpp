/************************
Author:Anish Kumar Jha
College:Army Institute of Technology ,Pune
*********************
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#define mod 1000000007
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define pf printf
#define sf(a) scanf("%d",&a)
#define sfl(a) scanf("%lld",&a)
#define ll long long 
using namespace std;

vector<int> v[200];
int visited[200],dist[200];
queue<int> q;

void bfs(int src)
{
	q.push(src);
	visited[src]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		FOR(i,0,v[u].size())
		{
			int p=v[u][i];
			if(visited[p]==0)
			{
				q.push(p);
				visited[p]=1;
				dist[p]=dist[u]+1;
			}
		}
	}


}


int main()
{
	int tc;
	sf(tc);
	while(tc--)
	{
		int n;
		sf(n);
		
		FOR(i,0,n-1)
		{
			int src,dst;
			sf(src);
			sf(dst);
			src--;
			dst--;
			v[src].push_back(dst);
			v[dst].push_back(src);
		}

		while(!q.empty())
			q.pop();

		memset(visited,0,sizeof visited);
		memset(dist,0,sizeof dist);

		bfs(1);

		int ans=dist[0];
		FOR(i,0,n)
		{
			if(dist[i]>ans)
				ans=dist[i];
		}

		pf("max depth of tree: %d\n",ans);
		
	}


}
