#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD=1e9+7;
ll fun(ll sum,vector<ll>&v,vector<ll>&dp)
{
	if(sum==0)return 1;
	if(dp[sum]!=-1)return dp[sum];
	ll ans=0;
	for(int i=0;i<v.size();i++)
	{
		if(v[i]<=sum)
		ans+=fun(sum-v[i],v,dp);
	}
	return dp[sum]=ans%MOD;
}
int main() {    
	ll n;cin>>n;
    ll sum;cin>>sum;
    vector<ll>dp(sum+1,0);
    vector<ll>v(n);
    for (int i = 0; i < n; ++i)
    {
    	cin>>v[i];
    }
    
    // memoization or recursive dp or pull dp
    //vector<ll>dp(sum+1,-1);
    //cout<<fun(sum,v,dp)%MOD;
    
    // tabulation or iterative dp
    dp[0]=1;
    for(int sm=1;sm<=sum;sm++)
    {
    	for(int index=0;index<v.size();index++)
    	{
    		if(v[index]<=sm)
    			dp[sm]+=(dp[sm-v[index]])%MOD;
    		
    	}
    }
    cout<<dp[sum]%MOD<<endl;
}