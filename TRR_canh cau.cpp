#include<bits/stdc++.h>
using namespace std;
vector<int>adj[101];
vector<pair<int,int>>dsc;
int visited[101]={0};
queue<int>q;
void dfs(int x,int u,int v)
{
	visited[x]=1;
	for(auto k:adj[x])
	{
		if((x==u&&k==v)||(x==v&&k==u)) continue;
		else if(!visited[k]) dfs(k,u,v);
	}
}
void bfs(int x,int u,int v)
{
	q.push(x);
	visited[x]=1;
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		for(auto k:adj[top])
		{
			if((top==u&&k==v)||(top==v&&k==u)) continue;
			else if(!visited[k]) 
			{
				visited[k]=1;
				q.push(k);
			}
		}
	}
}
void dfs1(int x)
{
	visited[x]=1;
	for(auto k:adj[x])
	{
		if(visited[k]==0) 
		dfs1(k);
	}
}
int main()
{
	ifstream in("TK.INP");
	ofstream out("TK.OUT");
	int n;in>>n;
	int a[101][101];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			in>>a[i][j];
			{
				if(a[i][j]&&i<j)
				{
					adj[i].push_back(j);
					adj[j].push_back(i);
					dsc.push_back({i,j});
				}
			}
		}
	}
	int cnt=0;vector<pair<int,int>>ans;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			cnt++;
		 	 dfs1(i);}
	}
	for(int i=0;i<dsc.size();i++)
	{
		int x=dsc[i].first,y=dsc[i].second;
		int cnt1=0;
		memset(visited,0,sizeof(visited));
		for(int j=1;j<=n;j++)
		{
			if(visited[j]==0)
			{
				cnt1++;
				dfs(j,x,y);//bfs(j,x,y)
			}
		}
		if(cnt1>cnt) ans.push_back({x,y});
	}
	out<<ans.size()<<endl;
	for(auto x:ans) out<<x.first<<" "<<x.second<<endl;
}
