#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD=1e9+7;
ll fun(ll row ,ll col , vector<vector<char> >&grid,vector<vector<ll> >&dp)
{
	if(row<0 || col<0)return 0;
	if(grid[row][col]=='*')return 0;
	if(row==0 && col==0)return 1;
	if(dp[row][col]!=-1)return dp[row][col];	
	ll above=fun(row-1,col,grid,dp);
	ll left=fun(row,col-1,grid,dp);
	return dp[row][col]=(above+left)%MOD;
}

int main() {    
	ll n;cin>>n;
	vector<vector<char> >grid(n,vector<char>(n));
	vector<vector<ll> >dp(n,vector<ll>(n,0));
	for (int i = 0; i < n; ++i)
	{
		for(int j=0;j<n;j++)
		{
			cin>>grid[i][j];
		}
	}
	
	// recursive solution
	// vector<vector<ll>>dp(n,vector<ll>(n,-1));
	// cout<<fun(n-1,n-1,grid,dp);

    // iterative solution
    
	if(grid[0][0]=='*')
	{
		cout<<0<<endl;
	}
	else
	{
		dp[0][0]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(grid[i][j]=='*')
					dp[i][j]=0;
				else 
				{
					if(i!=0)dp[i][j]+=dp[i-1][j];
					if(j!=0)dp[i][j]+=dp[i][j-1];					
				}
				dp[i][j]%=MOD;
			}
		}
		cout<<dp[n-1][n-1]<<endl;	
	}
}

