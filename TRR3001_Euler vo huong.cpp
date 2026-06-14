#include<bits/stdc++.h>
using namespace std;
set<int>adj[101];
vector<int>ke[101];
vector<int>EC;
stack<int>st;
int n,a[101][101],deg[101],visited[101],cnt=0;
ifstream in("CT.INP");
ofstream out("CT.OUT");
void dfs(int x)
{
	visited[x]=1;
	for(auto k:ke[x])
	{
		if(visited[k]==0) dfs(k);
	}
}
void euler(int x)
{
	st.push(x);
	while(!st.empty())
	{
		int top=st.top();
		if(adj[top].size()!=0)
		{
			int y=*adj[top].begin();
			st.push(y);
			adj[top].erase(y);
			adj[y].erase(top);
		}
		else{
			st.pop();
			EC.push_back(top);
		}
	}
	reverse(EC.begin(),EC.end());
}
void nhap()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			in>>a[i][j];
			if(a[i][j]&&i<j)
			{
				deg[i]++;deg[j]++;
				adj[i].insert(j);
				adj[j].insert(i);
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
		for(int i=1;i<=n;i++)
		{
			if(visited[i]==0&&deg[i]>0)
			{
				cnt++;dfs(i);
			}
		}
		if(cnt>1) {out<<"0";return 0;}
		int dem=0;
		for(int i=1;i<=n;i++)
		{
			if(deg[i]%2!=0)
			{
				dem++;
			}
		}
		if(dem==2) out<<"2";
		else if(dem==0) out<<"1";
		else out<<"0";
	}
	else{
		int u;in>>n>>u;
		nhap();
		euler(u);
		for(auto x:EC) out<<x<<" ";
	}
}

