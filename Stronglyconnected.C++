#include <bits/stdc++.h>
 
using namespace std;
 
const int maxN = 10010; // Số lượng đỉnh tối đa

int n, m; // Số lượng đỉnh và số lượng cạnh
bool joint[maxN]; // Mảng đánh dấu các đỉnh nút
int timeDfs = 0, bridge = 0; // Biến thời gian DFS và số lượng cầu
int low[maxN], num[maxN]; // Mảng thời gian thăm sớm nhất và thời gian thăm của đỉnh u
vector <int> g[maxN]; // Danh sách kề của đỉnh u
 
void dfs(int u, int pre) {
    int child = 0; // Số lượng con trực tiếp của đỉnh u trong cây DFS
    num[u] = low[u] = ++timeDfs; // Gán thời gian thăm và thời gian thăm sớm nhất của đỉnh u
    for (int v : g[u]) {     // Duyệt qua các đỉnh kề với đỉnh u
        if (v == pre) continue; // Nếu v là đỉnh cha của u thì bỏ qua
        if (!num[v]) {
            dfs(v, u); // Gọi đệ quy DFS từ v
            low[u] = min(low[u], low[v]); // Gán thời gian thăm sớm nhất của đỉnh u
            if (low[v] == num[v]) bridge++; // Nếu thời gian thăm sớm nhất của v bằng thời gian thăm của v thì cạnh (u, v) là cầu
            child++; // Tăng số lượng con lên 1
            if (u == pre) { // Nếu u là đỉnh gốc của cây DFS
                if (child > 1) joint[u] = true; // Nếu u có nhiều hơn 1 con thì u là điểm nút
            }
            else if (low[v] >= num[u]) joint[u] = true; // Nếu thời gian thăm sớm nhất của v lớn hơn hoặc bằng thời gian thăm của u thì u là điểm nút
        }
        else low[u] = min(low[u], num[v]); // Gán thời gian thăm sớm nhất của u
    }
}
 
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) 
        if (!num[i]) dfs(i, i);

    int cntJoint = 0;
    for (int i = 1; i <= n; i++) cntJoint += joint[i];

    cout << cntJoint << ' ' << bridge;
} 