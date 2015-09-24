// You are given a m x n 2D grid initialized with these three possible values.
//
// -1 - A wall or an obstacle.
// 0 - A gate.
// INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
//
// For example, given the 2D grid:
// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF
// After running your function, the 2D grid should be:
// 3  -1   0   1
// 2   2   1  -1
// 1  -1   2  -1
// 0  -1   3   4

// Solution typical parallel BFS
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        // parallel BFS from all the gate.
        int m = rooms.size();
        if (m == 0)
            return;
        int n = rooms[0].size();
        if (n == 0)
            return;
        
        // Visited array
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // queue for parallel BFS.
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = true;
                } else if (rooms[i][j] == -1) {
                    visited[i][j] = true;
                }
            }
        }
        
        // Parallel BFS.
        int level = 0;
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};
        while (!q.empty()) {
            level++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int xx = x + dx[j];
                    int yy = y + dy[j];
                    if (xx >= 0 && xx < m && yy >= 0 && yy < n && !visited[xx][yy]) {
                        rooms[xx][yy] = level;
                        visited[xx][yy] = true;
                        q.push({xx, yy});
                    }
                }
            }
        }
        return;
    }
};
