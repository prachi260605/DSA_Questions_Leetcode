class Solution {
public:
    void bfs(vector<vector<int>>& image, vector<vector<int>>& vis, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int currVal = image[sr][sc];
        image[sr][sc] = color;
        vis[sr][sc] = 1;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nrow = row + delRow[k];
                int ncol = col + delCol[k];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && image[nrow][ncol] == currVal) {
                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));

        bfs(image, vis, sr, sc, color);

        return image;
    }
};
