#include<bits/stdc++.h>
using namespace std;
int n,m;
bool vis[1001][1001];
char s[1001][1001];
bool reach(int x,int y){
    if(x>=n||y>=m||x<0||y<0)return false;
    if(vis[x][y]==true || s[x][y]=='#')return false;
    return true;
}
void dfs(int x,int y){
    vis[x][y]=true;
    if(reach(x,y+1))dfs(x,y+1);
    if(reach(x,y-1))dfs(x,y-1);
    if(reach(x+1,y))dfs(x+1,y);
    if(reach(x-1,y))dfs(x-1,y);
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>s[i][j];
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && s[i][j]=='.'){
                dfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}