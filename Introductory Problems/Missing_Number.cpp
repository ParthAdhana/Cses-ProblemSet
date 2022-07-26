//spoken like a true politician 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(c,a,b) for(c=a;c<b;c++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll i,j;
ll mod=1e9+7,mx=0,mn=1e9+7;
//code
void solve(){
    ll n;cin>>n;
    ll arr[n],sm=0;
    loop(i,0,n-1){
        cin>>arr[i];
        sm+=arr[i];
    }
    ll sum=(n*(n+1))/2;
    cout<<sum-sm;
}
 
int main(){
    IOS;
    
        solve();
}