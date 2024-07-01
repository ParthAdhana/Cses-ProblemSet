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
    while(n!=1){
        cout<<n<<" ";
        if(n%2==0){
            n/=2;
        }
        else{
            n*=3;
            n++;
        }
    }
    cout<<1;
}
 
int main(){
    IOS;
    
        solve();
}