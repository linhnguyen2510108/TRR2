#include<bits/stdc++.h>
using namespace std;
int n,a[101][101],degc[101]={0},degt[101]={0};
set<int>adj[101];
vector<int>EC;
vector<int>ke[101];
stack<int>st;
int visited[101]={0};
int cnt=0;
ifstream in("CT.INP");
	ofstream out("CT.OUT");
void euler(int x)
{
	st.push(x);
	while(!st.empty())
	{
		int top=st.top();
		if(adj[top].size()!=0)
		{
			int k=*adj[top].begin();
			st.push(k);
			adj[top].erase(k);
		}
		else{
			EC.push_back(top);
			st.pop();
		}
	}
	reverse(EC.begin(),EC.end());
}
void dfs(int x)
{
	visited[x]=1;
	for(auto k:ke[x])
	{
		if(!visited[k])	dfs(k);
	}
}
void nhap()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			in>>a[i][j];
			if(a[i][j])
			{
				degc[i]++;degt[j]++;
				adj[i].insert(j);
				ke[i].push_back(j);
				ke[j].push_back(i);
			}
		}
	}
}
int main()
{
	int t;in>>t;
	if(t==1)
	{
		in>>n;
		nhap();
		int ra=0,vao=0,ok=0;
		for(int i=1;i<=n;i++)
		{
			 if(degc[i]-degt[i]==1) ra++;
			else if(degc[i]-degt[i]==-1) vao++;
			if(degc[i]-degt[i]!=0) {
				out<<"0"; return 0;}
			}
		for(int i=1;i<=n;i++)
		{
			if(visited[i]==0&&(degc[i] > 0 || degt[i] > 0))
			{
				cnt++;
				dfs(i);
			}
		}
		if(cnt>1)  {
		out<<"0";return 0;}
		if(ra!=1||vao!=1) out<<"0";
		else if(ra==1&&vao==1) out<<"2";
		else if(ra==0&&vao==0)out<<"1";
		else out<<"0";
	}
	else{
		int u;in>>n>>u;
		nhap();
		euler(u);
		for(auto x:EC) out<<x<<" ";
	}
}
