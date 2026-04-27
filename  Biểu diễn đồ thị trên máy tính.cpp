#include<bits/stdc++.h>
using namespace std;
int n,m,a[101][101]={0},c[101][101];
vector<int>adj[101];
void matranke()
{
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++) cin>>a[i][j];
	}	
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++) cout<<a[i][j];
	}	
}
void matranlienthuoc()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) cin>>a[i][j]; //a[i][j]=1 neu dinh i lien thuoc vs canh j
											// a[i][j]=1 neu i la cung ra,-1 neu la cung vao dothi co huong
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) cout<<a[i][j]; 
	}
}
void matrantrongso()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) cin>>c[i][j]; //a[i][j]=Z,0,vô cùng
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) cout<<c[i][j]; 
	}
}
void danhsachcanh()
{
	while(m--)
	{
		int x,y;cin>>x>>y;
		adj[x].push_back(y);// chuyen sang dach sach ke voi mtran co huong
		a[x][y]=a[y][x]=1; // matranke vo huong
	}
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++) cout<<a[i][j];
	cout<<endl;
	}
}
void danhsachke()
{
	for(int i=1;i<=n;i++)
	{
		string s;
		getline(cin,s);
		stringstream ss(s);
		int tmp;
		while(ss>>tmp)
		{
			adj[i].push_back(tmp); 
			a[i][tmp]=1; // chuyen sang matranke
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(auto x:adj[i]) cout<<x<<" ";
		cout<<endl;
	}
}
int main()
{
	cin>>n>>m;
	danhsachcanh();
}
