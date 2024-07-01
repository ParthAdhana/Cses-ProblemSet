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
    string s;
    cin>>s;
    ll mx=0,temp=0;
    loop(i,0,s.length()-1){
        if(s[i]==s[i+1]){
            temp++;
            mx=max(mx,temp);
            
        }
        else
        temp=0;
    }
    cout<<mx+1;
}
 
int main(){
    IOS;
    
        solve();
}