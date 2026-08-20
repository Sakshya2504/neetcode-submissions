class Solution {
public:
    int m, n;

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<bool>>& vis) {

        if(r < 0 || r >= m || c < 0 || c >= n)
            return;

        if(vis[r][c])
            return;

        vis[r][c] = true;

        // Down
        if(r + 1 < m && heights[r + 1][c] >= heights[r][c])
            dfs(r + 1, c, heights, vis);

        // Up
        if(r - 1 >= 0 && heights[r - 1][c] >= heights[r][c])
            dfs(r - 1, c, heights, vis);

        // Right
        if(c + 1 < n && heights[r][c + 1] >= heights[r][c])
            dfs(r, c + 1, heights, vis);

        // Left
        if(c - 1 >= 0 && heights[r][c - 1] >= heights[r][c])
            dfs(r, c - 1, heights, vis);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific
        for(int j = 0; j < n; j++)
            dfs(0, j, heights, pacific);

        for(int i = 0; i < m; i++)
            dfs(i, 0, heights, pacific);

        // Atlantic
        for(int j = 0; j < n; j++)
            dfs(m - 1, j, heights, atlantic);

        for(int i = 0; i < m; i++)
            dfs(i, n - 1, heights, atlantic);

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};