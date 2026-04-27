#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,a[101][101]={0},c[101][101];
vector<int>adj[101];
int visited[101],parent[101];
queue<int>q;
vector<int>Path;
int cnt=0;
void dfs(int u)
{
	cout<<u<<" ";
	visited[u]=1;
	for(auto x:adj[u])
	{
		if(!visited[x])
		{
			parent[x]=u;// truy vet duong di
			dfs(x);
		}
	}
}
void bfs(int u)
{
	q.push(u);
	cout<<u<<" ";
	visited[u]=1;
	while(!q.empty())
	{
		int x=q.front();
		for(auto l:adj[x])
		{
			if(!visited[l])
			{
				cout<<l<<" ";
				visited[l]=1;
				q.push(l);
				parent[l]=x;//truy vet
			}
		}
	}
}
void path(int u,int v)
{
	if(parent[v]==-1) cout<<"Khong co duong di";
	else
	{
		while(v!=u)
		{
			Path.push_back(v);
			v=parent[v];
		}
		Path.push_back(u);
		reverse(Path.begin(),Path.end());
		for(auto x:Path) cout<<x<<" ";
	}
}
void TPLT()
{
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			cnt++;
			dfs(i);// bfs(i)
		}
	}
	cout<<cnt;
}
int main()
{
	int t; cin>>t;
	while(t--)
	{
		memset(visited,0,sizeof(visited));
		memset(parent,-1,sizeof(parent));
		for(int i=0;i<101;i++) adj[i].clear();
		cin>>n>>m>>u>>v;
		// nhap do thi theo de cho 
		dfs(u);
		bfs(u);
		path(u,v);
		TPLT();
	}
}
