#include<bits/stdc++.h>
using namespace std;

void DFS1(int v, bool visited[], stack<int> &Stack, vector<int> adj[]) {
    visited[v] = true;
    for(auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFS1(*i, visited, Stack, adj);
    Stack.push(v);
}

void DFS2(int v, bool visited[], vector<int> adj[]) {
    visited[v] = true;
    for(auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFS2(*i, visited, adj);
}

int findSCCs(int V, vector<int> adj[]) {
    stack<int> Stack;
    bool visited[V];
    memset(visited, false, sizeof(visited));

    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            DFS1(i, visited, Stack, adj);

    vector<int> adjT[V];
    for(int v = 0; v < V; v++)
        for(auto i = adj[v].begin(); i != adj[v].end(); ++i)
            adjT[*i].push_back(v);

    memset(visited, false, sizeof(visited));
    int count = 0;
    while(!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();
        if(visited[v] == false) {
            DFS2(v, visited, adjT);
            count++;
        }
    }
    return count;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> adj[N];
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1); // giả sử các nút được đánh số từ 1
    }
    cout << findSCCs(N, adj);
    return 0;
}