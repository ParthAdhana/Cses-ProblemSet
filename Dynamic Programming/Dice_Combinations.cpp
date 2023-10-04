#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD=1e9+7;
ll fun(ll n,vector<ll>&dp)
{
	if(n==0)return 1;
	if(dp[n]!=-1)return dp[n];
	ll ans=0;
	for(int i=1;i<=6;i++)
		if(n>=i)ans+=(fun(n-i,dp)%MOD);
	
	return dp[n]=ans%MOD;
}
int main() {    

	ll n;cin>>n;
    vector<ll>dp(n+1,0);
    
    // recursive solution 
    // vector<ll>dp(n+1,-1);
    //cout<<fun(n,dp)<<endl;
    
    // iterative solution
    dp[0]=1;
    for(int number=1;number<=n;number++)
    {
    	for(int dice=1;dice<=6;dice++)
    		if(number>=dice)
    		{
    			dp[number]+=(dp[number-dice])%MOD;
    		}
    }
    cout<<dp[n]%MOD<<endl;
}

