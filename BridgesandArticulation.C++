#include<bits/stdc++.h>
using namespace std;

#define NIL -1 

vector<int> *adj; // Danh sách kề
int *disc, *low, *parent; // Mảng disc, low, parent
bool *visited, *ap; // Mảng visited, ap
int times = 0, bridges = 0, points = 0; // Biến time, bridges, points

void APandBridges(int u) { // Tìm các điểm nút và cầu
    int children = 0; // Số lượng con của nút u
    visited[u] = true; // Đánh dấu nút đã được thăm
    disc[u] = low[u] = ++times; // Gán thời gian thăm và thời gian thăm sớm nhất của nút u
    for (int v : adj[u]) { // Duyệt qua các nút kề với nút u
        if (!visited[v]) { // Nếu nút chưa được thăm
            children++; // Tăng số lượng con lên 1
            parent[v] = u; // Gán nút u là cha của nút v
            APandBridges(v); // Thăm nút v
            low[u] = min(low[u], low[v]); // Gán thời gian thăm sớm nhất của nút u
            if (parent[u] == NIL && children > 1) { //  Nếu nút u là nút gốc và có nhiều hơn 1 con
                points++;
                ap[u] = true;
            }
            if (parent[u] != NIL && low[v] >= disc[u]) {
                points++;
                ap[u] = true;
            }
            if (low[v] > disc[u]) {
                bridges++;
            }
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    adj = new vector<int>[N];
    disc = new int[N];
    low = new int[N];
    parent = new int[N];
    visited = new bool[N];
    ap = new bool[N];
    for (int i = 0; i < N; i++) {
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    for (int i = 0; i < N; i++) {
        if (visited[i] == false) {
            APandBridges(i);
        }
    }
    cout << points << " " << bridges;
    return 0;
}