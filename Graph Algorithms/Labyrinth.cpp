#include<bits/stdc++.h>
using namespace std;
int n,m;
bool vis[1001][1001];
char s[1001][1001];
char grid[1001][1001];
vector<char>path;
bool reach(int x,int y){
    if(x>=n||y>=m||x<0||y<0)return false;
    if(vis[x][y]==true || s[x][y]=='#')return false;
    return true;
}
bool bfs(int x,int y){
    vis[x][y]=true;
    queue<pair<int,int> >q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int a=q.front().first,b=q.front().second;
        q.pop();
 
        if(s[a][b]=='B'){
            while(1){
                path.push_back(grid[a][b]);
 
                if(path.back()=='L')b++;
                if(path.back()=='R')b--;
                if(path.back()=='U')a++;
                if(path.back()=='D')a--;
                
                if(a==x && b==y)break;
            }
            
            return 1;
        }
        if(reach(a,b+1))q.push(make_pair(a,b+1)),grid[a][b+1]='R',vis[a][b+1]=true;
        if(reach(a,b-1))q.push(make_pair(a,b-1)),grid[a][b-1]='L',vis[a][b-1]=true;
        if(reach(a+1,b))q.push(make_pair(a+1,b)),grid[a+1][b]='D',vis[a+1][b]=true;
        if(reach(a-1,b))q.push(make_pair(a-1,b)),grid[a-1][b]='U',vis[a-1][b]=true;
    }
    return 0;
}
int main(){
    cin>>n>>m;
    int x,y;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>s[i][j];
            if(s[i][j]=='A')
            x=i,y=j;
        }
    if(bfs(x,y)){
        cout<<"YES"<<endl;
        cout<<path.size()<<endl;
        while(path.size() > 0) cout<<path.back() , path.pop_back();
    }
    else{
        cout<<"NO"<<endl;
    }
    
}