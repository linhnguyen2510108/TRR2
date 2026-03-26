#include<bits/stdc++.h>
using namespace std;
int a[101][101]={0},n,m,t, c[101][101];
vector<int>adj;
vector<pair<int,int>>v;
int main()
{
	ifstream in("DT.INP");
	ofstream out("DT.OUT");
	in>>t>>n;
	for(int i = 1; i <= n; i++)
    {
    	for(int j=1;j<=n;j++)
    	in>>c[i][j];
    }
    int ans=0;
    for(int i = 1; i <= n; i++)
    {
    	int sum=0;
    	for(int j=1;j<=n;j++)
    	{
    		if(c[i][j]>0&&c[i][j]<=50)
    		{
    			sum++;
			}
		}
		adj.push_back(sum);
    }	
	for(int i = 1; i <= n; i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(c[i][j]>0&&c[i][j]<=50&&i<j)
    		{
    			ans++;
    			a[i][j]=c[i][j];
			}
		}
    }	
	if(t==1) {
		for(auto x:adj) out<<x<<" ";
	}
	else	
	{
		out<<n<<" "<<ans<<endl;
		for(int i = 1; i <= n; i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(a[i][j]!=0) out<<i<<" "<<j<<" "<<a[i][j]<<endl;
    	}
    }	
	}
	in.close();
	out.close();
}

