#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e6;
int vis[N]={0};
vector<char>path;
vector<int>adj[N];
vector<int>roads;
void dfs(int node){
   vis[node]=1;
   for(auto it : adj[node])
   if(vis[it]==0)dfs(it);
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            roads.push_back(i);
            dfs(i);
        }
    }
    
    cout<<roads.size()-1<<endl;
    for(int i=0;i<roads.size()-1;i++){
        cout<<roads[i]<<" "<<roads[i+1]<<endl;
    }
    
}