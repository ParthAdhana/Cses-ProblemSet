#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*    *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *    *    *   */
         
/*



*/
int dp[501][501];

int fun(int a, int b)
{
    if(a==b)return 0;
    if(a==1)return dp[a][b]=dp[b][a]=b-1;
    if(b==1)return dp[a][b]=dp[b][a]=a-1;
    if(dp[a][b])return dp[a][b];
    if(dp[b][a])return dp[b][a];
    int ans=INT_MAX;
    for(int i=1;i<a;i++)
    {
        ans=min(ans,1+fun(i,b)+fun(a-i,b));
    }
    for(int i=1;i<b;i++)
    {
        ans=min(ans,1+fun(a,i)+fun(a,b-i));
    }
    return dp[a][b]=dp[b][a]=ans;
   
}
void solve()
{
    int a,b;cin>>a>>b;
    for(int i=0;i<501;i++)
    {
        for(int j=0;j<501;j++)
        {
            dp[i][j]=0;
        }
    }
    
    cout<<fun(a,b)<<endl;
    // for(int i=0;i<6;i++)
    // {
    //     for(int j=0;j<6;j++)
    //     {
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    
    
    
}

int main() {    
// #ifndef ONLINE_JUDGE
//     freopen("error.txt", "w", stderr);
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif
    
    fastio();
    solve();
}

