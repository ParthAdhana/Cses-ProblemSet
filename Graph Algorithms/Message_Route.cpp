#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e6;
int vis[N]={0};
vector<char>path;
vector<int>adj[N];
int traverse[N]={0};
vector<int>ans;
 
int main(){
    cin>>n>>m;
    for(int i=0,a,b;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        
        for(auto next : adj[node]){
            if(traverse[next]==0){
                traverse[next]=node;
                q.push(next);
            }
        }
    }
    if(traverse[n]==0){
        cout<<"IMPOSSIBLE";
    }
    else{
        while(n!=1){
            ans.push_back(n);
            n=traverse[n];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
}