class Solution {
public:
    int m, n;

    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int freshOranges = 0, rottenOranges = 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    freshOranges++;
                } else if (grid[i][j] == 2) {
                    rottenOranges++;
                    q.push({i, j});
                }
            }
        }

        if (freshOranges == 0)
            return 0;

        if (q.empty())
            return -1;

        int minutes = -1;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                pair<int, int> p = q.front();

                q.pop();

                int dirs[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

                for (int k = 0; k < 4; k++) {
                    int xx = dirs[k][0] + p.first;
                    int yy = dirs[k][1] + p.second;

                    if (check(grid, xx, yy)) {
                        freshOranges--;
                        grid[xx][yy] = 2;
                        q.push({xx, yy});
                    }
                }
            }

            minutes++;
        }

        if (freshOranges != 0)
            return -1;

        return minutes;
    }

    bool check(vector<vector<int>>& grid, int xx, int yy) {
        if (xx < 0 || xx == m || yy < 0 || yy == n)
            return false;

        if (grid[xx][yy] != 1)
            return false;

        return true;
    }
};