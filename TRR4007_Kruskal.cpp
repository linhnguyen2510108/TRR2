#include<bits/stdc++.h>
using namespace std;
int par[101],sz[101],n;
struct edge{
	int u,v,w;
};
void makeset()
{
	for(int i=1;i<=n;i++)
	{
		par[i]=i;
		sz[i]=1;
	}
}
int find(int x)
{
	if(x==par[x]) return x;
	return par[x]=find(par[x]);
}
bool Union(int a,int b)
{
	a=find(a);b=find(b);
	if(a==b) return false;
	else if(sz[a]<sz[b]) swap(a,b);
	par[b]=a;
	sz[a]+=sz[b];
	return true;
}
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int main()
{
	
	ifstream in("CK.INP");
	ofstream out("CK.OUT");
	
	 cin>>n;int m;cin>>m;
	 makeset();
	vector<edge>v;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;cin>>x>>y>>z;
		v.push_back({x,y,z});
	}
	sort(v.begin(),v.end(),cmp);
	vector<edge>MST;
	int d=0;
	for(int i=0;i<m;i++)
	{
		edge e=v[i];
		if(MST.size()==n-1) break;
		if(Union(e.u,e.v)) {
			MST.push_back(e);
			d+=e.w;
		}
	}
	if((int)MST.size()!=n-1) cout<<"0";
	else{
		cout<<d<<endl;
		for(auto x:MST) cout<<x.u<<" "<<x.v<<" "<<x.w<<endl;
	}
}
