#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream in("DN.INP");
	ofstream out("DN.OUT");
	int n,s,t; in>>n>>s>>t;
	int c[101][101],d[101],par[101];
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			in>>c[i][j];
			if(i==s) {
				par[j]=i;
				d[j]=c[i][j];
				if (i==j) continue;
				q.push({d[j],j});
			}
		}
	}
	while(!q.empty())
	{
		pair<int,int>top=q.top();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if(d[i]>top.first+c[top.second][i])
			{
				d[i]=top.first+c[top.second][i];
				par[i]=top.second;
				q.push({d[i],i});
			}
		}
	}
	if(d[t]==10000) out<<"0";
	else
	{
		out<<d[t]<<endl;
		vector<int>path;
		while(t!=s)
		{
			path.push_back(t);
			t=par[t];
		}
		path.push_back(s);
		reverse(path.begin(),path.end());
		for(auto x:path) out<<x<<" ";
	}
}
