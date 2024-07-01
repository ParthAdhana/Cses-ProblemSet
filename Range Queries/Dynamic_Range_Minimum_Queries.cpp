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
 
// Segment tree tree declared globaly so clear after every test case
vector<ll> tree; 
void init(vector<ll> &a, ll &n) //O(N)
{
    while (__builtin_popcountll(n) != 1)n++,a.pb(0);
    tree.resize(2 * n);
    
    for (ll i = 0; i < n; i++)tree[n + i] = a[i];// create tree ,fill leaf node from array a
        
    for (ll i = n - 1; i >= 1; i--)tree[i] = min(tree[2 * i] , tree[2 * i + 1]);// fill all other parent nodes
}
 
ll get_min(ll node, ll node_low, ll node_high, ll query_low, ll query_high)// O(log N)
{
    if (query_low <= node_low && node_high <= query_high)//query range completely inside node's range
        return tree[node];
    if (node_high < query_low || query_high < node_low)// query range completely outside node's range
        return INF;
    
    ll mid = (node_high + node_low) / 2;
    return min(get_min(2 * node, node_low, mid, query_low, query_high) ,
        get_min(2 * node+1, mid+1 , node_high , query_low, query_high));
}
 
// call for pos+n in main
void update(ll pos, ll v) // O(log N)
{
    tree[pos] = v;
    for (ll j = pos / 2; j >= 1; j = j / 2)
        tree[j] = min(tree[2 * j + 1] , tree[2 * j]);
}
 
void solve()
{
    ll n,q;cin>>n>>q;
    vector<ll>v(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }
    init(v,n);
    while(q--)
    {
        ll type;cin>>type;
        if(type==1)
        {
            ll pos,u;cin>>pos>>u;
            pos--;   
            update(pos+n,u);
        }
        else
        {
            ll a,b;cin>>a>>b;
            a--;b--;
            cout<<get_min(1,0,n-1,a,b)<<endl;;
        }
        
    }
    
}
 
int main() {    
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
    fastio();
    ll T;T=1;
    while(T--){
        solve();
    }
}