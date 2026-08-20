class Solution {
public:
    int m, n;

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<bool>>& vis) {

        vis[r][c] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // Out of bounds
            if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            // Already visited
            if(vis[nr][nc])
                continue;

            // We can move from current cell to neighbor
            // only if neighbor is higher or equal
            if(heights[nr][nc] < heights[r][c])
                continue;

            dfs(nr, nc, heights, vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific: top row
        for(int j = 0; j < n; j++) {
            dfs(0, j, heights, pacific);
        }

        // Pacific: left column
        for(int i = 0; i < m; i++) {
            dfs(i, 0, heights, pacific);
        }

        // Atlantic: bottom row
        for(int j = 0; j < n; j++) {
            dfs(m - 1, j, heights, atlantic);
        }

        // Atlantic: right column
        for(int i = 0; i < m; i++) {
            dfs(i, n - 1, heights, atlantic);
        }

        vector<vector<int>> ans;

        // Cell must be reachable from BOTH oceans
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};