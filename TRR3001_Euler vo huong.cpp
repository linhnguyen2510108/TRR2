#include<bits/stdc++.h>
using namespace std;
vector<int>adj[101];
int visited[101]={0};
void dfs(int x)
{
	visited[x]=1;
	for(auto k:adj[x])
	{
		if(visited[k]==0) dfs(k);
	}
}
queue<int>q;
void bfs(int x)
{
	q.push(x);visited[x]=1;
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		for(auto k:adj[top])
		{
			if(!visited[k])
			{
				visited[k]=1;
				q.push(k);
			}
		}
	}
}
int main()
{
	ifstream in("TK.INP");
	ofstream out("TK.OUT");
	int n; in>>n;
	int a[101][101];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			in>>a[i][j];
			if(a[i][j]&&i<j)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	int cnt=0,dem=0;
	vector<int>ans;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			cnt++; bfs(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		memset(visited,0,sizeof(visited));
		visited[i]=1;
		int cnt1=0;
		for(int j=1;j<=n;j++)
	{
		if(visited[j]==0)
		{
			cnt1++; bfs(j);
		}
	}
	if(cnt1>cnt)
	{
		dem++;ans.push_back(i);
	}
	}
	out<<dem<<endl;
	for(auto x:ans) out<<x<<" ";
}
