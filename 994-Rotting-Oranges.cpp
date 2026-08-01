class Solution {
public:
    int bfs(vector<vector<int>>& grid, int n, int m,vector<vector<bool>> &vis) {

        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }
       // cout<<1;
        int sol = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
       // cout<<2;
        while (!q.empty()) {
            int u = q.front().first.first;
            int v = q.front().first.second;
            int t = q.front().second;
            q.pop();
            sol = max(sol, t);
            //cout<<u<<v<<t;
            for (auto a : dirs) {
                int u1 = u + a.first;
                int v1 = a.second + v;
                if (u1 >= 0 && u1 < n && v1>=0 && v1<m&& grid[u1][v1] == 1) {
                    if (!vis[u1][v1]) {
                        q.push({{u1, v1}, t + 1});
                        vis[u1][v1] = true;
                    }
                }
            }
        }
        return sol;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int n =  bfs(grid, grid.size(), grid[0].size(),vis);

         for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j <grid[0].size(); j++) {
                if (grid[i][j] == 1 && vis[i][j]!=true) {
                    return -1;
                }
            }
        }
        return n;
        
    }
};