#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> adj[100000];
//danh sach ke
bool visited[100000];
//mang kiem tra da tham hay chua
void input(){
 cin>>n>>m;
 for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
 }
 memset(visited,false,sizeof(visited));
}
void dfs(int u){
    cout<<u<<" ";
    visited[u]=true;
    for(int v:adj[u] ){
        if(visited[v]==false){
            dfs(v);
        }
    }

}
int main(){
 input();
 dfs(1);
}
