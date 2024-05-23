#include<bits/stdc++.h>
using namespace std;

void DFS1(int v, bool visited[], stack<int> &Stack, vector<int> adj[]) { // DFS theo chiều sâu
    visited[v] = true; // Đánh dấu nút đã được thăm
    for(auto i = adj[v].begin(); i != adj[v].end(); ++i) // Duyệt qua các nút kề với nút v
        if(!visited[*i]) // Nếu nút chưa được thăm
            DFS1(*i, visited, Stack, adj);
    Stack.push(v);
}

void DFS2(int v, bool visited[], vector<int> adj[]) { // DFS theo chiều sâu
    visited[v] = true; // Đánh dấu nút đã được thăm
    for(auto i = adj[v].begin(); i != adj[v].end(); ++i)   // Duyệt qua các nút kề với nút v
        if(!visited[*i]) // Nếu nút chưa được thăm
            DFS2(*i, visited, adj);  // Thăm nút đó
}

int findSCCs(int V, vector<int> adj[]) { // Tìm số lượng thành phần liên thông mạnh
    stack<int> Stack; //    Stack để lưu trữ các nút
    bool visited[V]; // Mảng visited để đánh dấu các nút đã được thăm
    memset(visited, false, sizeof(visited)); // Khởi tạo mảng visited

    for(int i = 0; i < V; i++) // Duyệt qua tất cả các nút
        if(visited[i] == false) //  Nếu nút chưa được thăm
            DFS1(i, visited, Stack, adj); // Thăm nút đó

    vector<int> adjT[V];    // Ma trận kề của đồ thị chuyển vị
    for(int v = 0; v < V; v++) // Duyệt qua tất cả các nút
        for(auto i = adj[v].begin(); i != adj[v].end(); ++i) // Duyệt qua các nút kề với nút v
            adjT[*i].push_back(v); //   Thêm nút v vào danh sách kề của nút *i

    memset(visited, false, sizeof(visited)); // Khởi tạo mảng visited
    int count = 0; //   Biến đếm số lượng thành phần liên thông mạnh
    while(!Stack.empty()) { // Duyệt qua tất cả các nút trong Stack
        int v = Stack.top();// Lấy nút đầu tiên trong Stack
        Stack.pop(); // Xóa nút đó khỏi Stack
        if(visited[v] == false) { // Nếu nút chưa được thăm
            DFS2(v, visited, adjT); // Thăm nút đó
            count++;// Tăng biến đếm lên 1
        }
    }
    return count; //      Trả về số lượng thành phần liên thông mạnh
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