class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Find first land cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    break;
                }
            }
            if (!q.empty()) break;
        }

        int perimeter = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                // Outside grid -> perimeter
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    perimeter++;
                }
                // Water -> perimeter
                else if (grid[nx][ny] == 0) {
                    perimeter++;
                }
                // Unvisited land -> graph edge, visit it
                else if (!vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return perimeter;
    }
};