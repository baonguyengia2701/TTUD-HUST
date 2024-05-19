#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x, y, steps;
};

int findShortestPath(vector<vector<int>>& maze, int startRow, int startCol) {
    int n = maze.size();
    int m = maze[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<Point> q;

    q.push({startRow, startCol, 0});
    visited[startRow][startCol] = true;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (maze[current.x][current.y] == 1) {
            // Wall, skip this cell
            continue;
        }

        if (current.x == 0 || current.x == n - 1 || current.y == 0 || current.y == m - 1) {
            // Reached the border, this is the exit
            return current.steps;
        }

        // Check neighbors
        vector<pair<int, int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto& neighbor : neighbors) {
            int nx = current.x + neighbor.first;
            int ny = current.y + neighbor.second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                q.push({nx, ny, current.steps + 1});
                visited[nx][ny] = true;
            }
        }
    }

    // No path found
    return -2;
}

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    vector<vector<int>> maze(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
        }
    }

    int result = findShortestPath(maze, r - 1, c - 1);

    cout << result + 1 << endl;

    return 0;
}
