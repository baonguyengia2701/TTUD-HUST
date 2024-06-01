//C++ 
#include <bits/stdc++.h> 
using namespace std;

struct Point
{
    int x,y;
    int step;
};
int dfs( vector<vector<int>> &maze, int startRow,int startCow ){
    int n=maze.size();
    int m=maze[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    queue<Point> q;
    q.push({startRow,startCow,0});
    visited[startRow][startCow]=true;
    while(!q.empty()){
        Point p=q.front();
        q.pop();
        if(maze[p.x][p.y]==1){
            continue;
        }
        if(p.x==n-1 || p.y==m-1 ||p.x==0 || p.y==0){
            return p.step;
        }
        //Check neighbours
        vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
        for(const auto& neighbour:dirs){
            int nx=p.x+neighbour.first;
            int ny=p.y+neighbour.second;
            if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny]){
                q.push({nx,ny,p.step+1});
                visited[nx][ny]=true;
            }
        }
    }
    return -1;

}

int main() 
{ 
 int n,m,r,c;
 cin >> n>> m>>r>>c;
 vector<vector<int>> maze(n,vector<int>(m));
 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
         cin>>maze[i][j];
     }
 }
 int result = dfs(maze,r-1,c-1);
 cout<< result +1 <<endl;
}