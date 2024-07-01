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
    if(n==2||n==3){
        cout<<"NO SOLUTION";
        return;
    }
    else if(n==4){
        cout<<"3 1 4 2";
    }
    else{
        for(int i=1;i<=n;i+=2){
            cout<<i<<" ";
        }
        for(int i=2;i<=n;i+=2){
            cout<<i<<" ";
        }
    }
    
}
 
int main(){
    IOS;
    
        solve();
}