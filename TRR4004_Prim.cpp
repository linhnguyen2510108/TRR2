#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
};
int main()
{
	ifstream in("CK.INP");
	ofstream out("CK.OUT");
	int n,s;in>>n>>s;
	int c[101][101];
	vector<pair<int,int>>adj[101];
	int visited[101]={0};
	visited[s]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			in>>c[i][j];
			if(i<j){
			adj[i].push_back({j,c[i][j]});
			adj[j].push_back({i,c[i][j]});
		}
		}
	}
	vector<edge>MST;int d=0;
	while(MST.size()<n-1)
	{
		int MIN=10000,k,l;
		for(int i=1;i<=n;i++)
		{
			if(visited[i])
			{
				for(auto x:adj[i])
				{
					if(!visited[x.first]&&x.second<MIN)
					{
						MIN=x.second;
						k=i,l=x.first;
					}
				}
			}
		}
		MST.push_back({k,l,MIN});
		d+=MIN;
		visited[l]=1;
	}
	if(MST.size()!=n-1) out<<"0";
	else
	{
		out<<d<<endl;
		for(auto x:MST) out<<min(x.u,x.v)<<" "<<max(x.u,x.v)<<" "<<x.w<<endl;
	}
}
