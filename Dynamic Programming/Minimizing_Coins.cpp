#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fun(ll money,vector<ll>&v,vector<ll>&dp)
{
	
	if(money==0)return 0;
	if(dp[money]!=-1)return dp[money];
	ll ans=INT_MAX;
	for (int i = 0; i < v.size(); ++i)
	{
		if(money>=v[i])
		{
			ll temp=fun(money-v[i],v,dp);
			if(temp!=INT_MAX)
			ans=min(ans,1+temp);
		}
	}
	return dp[money]=ans;
}

int main() {    
	ll n,money;cin>>n>>money;
	vector<ll>v(n);
	vector<ll>dp(money+1,INT_MAX);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	// recursive solution 
	// vector<ll>dp(money+1,-1);
	// fun(money,v,dp);
	// if(dp[money]==INT_MAX)dp[money]=-1;
	// cout<<dp[money]<<endl;
	
	// iterative solution
	dp[0]=0;
	for(int mn=0;mn<=money;mn++)
	{
		for(int index=0;index<n;index++)
		{
			if(mn>=v[index])
				dp[mn]=min(dp[mn],1+dp[mn-v[index]]);
		}
	}
	if(dp[money]>=INT_MAX)dp[money]=-1;
	cout<<dp[money]<<endl;
}

