#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
};
int n;
ifstream in("CK.INP");
	ofstream out("CK.OUT");
	vector<int>adj[101];
	int visited[101]={0};
	vector<pair<int,int>>MST;
void dfs(int s)
{
	visited[s]=1;
	for(auto x:adj[s])
	{
		if(!visited[x])
		{
			MST.push_back({s,x});
			dfs(x);
		}
	}
}
void indfs(int s)
{
	dfs(s);
	if(MST.size()!=n-1) cout<<"0";
	else{
		out<<n-1<<endl;
		for(auto x:MST) out<<min(x.first,x.second)<<" "<<max(x.first,x.second)<<endl;
	}
}
queue<int>q;
void bfs(int s)
{
	q.push(s);
	visited[s]=1;
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		for(auto x:adj[top])
		{
			if(visited[x]==0)
			{
				MST.push_back({top,x});
				q.push(x);
				visited[x]=1;
			}
		}
	}
	if(MST.size()!=n-1) out<<"0";
	else{
		out<<n-1<<endl;
		for(auto x:MST) out<<min(x.first,x.second)<<" "<<max(x.first,x.second)<<endl;
	}
}
int main()
{
	int t;in>>t;
	int s;in>>n>>s;
	int c[101][101];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			in>>c[i][j];
			if(i<j&&c[i][j]==1){
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
		}
	}
	if(t==1) indfs(s);
	else bfs(s);
}
