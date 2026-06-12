#include<bits/stdc++.h>
using namespace std;
vector<int>adj[101];
int X[101],visited[101]={0};int n,u;
vector<vector<int>>v;
void hal(int pos)
{
	for(auto x:adj[X[pos-1]])
		{
	if(x==u&&pos==n+1)
	{
		vector<int>tmp;
		for(int i=1;i<pos;i++) tmp.push_back(X[i]);
		tmp.push_back(u);
		v.push_back(tmp);
	}
	else
	{
			if(!visited[x])
			{
				X[pos]=x;
				visited[x]=1;
				hal(pos+1);
				visited[x]=0;
			}
		}
	}
}
int main()
{
	ifstream in("CT.INP");
	ofstream out("CT.OUT");
	in>>n>>u;
	int a[101][101];
	memset(visited,0,sizeof(visited));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			in>>a[i][j];
			if(a[i][j]) adj[i].push_back(j);
		}
	}
	X[1]=u;
	visited[u]=1;
	hal(2);
	if(v.size()==0) out<<"0";
	else
	{
		for(auto x:v)
		{
			for(auto l:x) out<<l<<" ";
			out<<endl;
		}
		out<<v.size();
	}
}
