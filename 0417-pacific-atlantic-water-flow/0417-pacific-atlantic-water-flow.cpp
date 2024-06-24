class Solution {
public:

    // void dfs(vector<vector<int>>& heights, vector<vector<bool>> &visited, int i, int j){

    //     int m = heights.size();
    //     int n = heights[0].size();

    //     visited[i][j] = true;

    //     if(i-1>=0 && !visited[i-1][j] && heights[i-1][j]>= heights[i][j]) dfs(heights, visited, i-1, j);

    //     if(i+1<m && !visited[i+1][j] && heights[i+1][j]>= heights[i][j]) dfs(heights, visited, i+1, j);

    //     if(j-1>=0 && !visited[i][j-1] && heights[i][j-1]>= heights[i][j]) dfs(heights, visited, i, j-1);

    //     if(j+1<n && !visited[i][j+1] && heights[i][j+1]>= heights[i][j]) dfs(heights, visited, i, j+1);
    // }

    bool isValid(int r, int c, int m, int n){
        return (r>=0 && r<m && c>=0 && c<n);
    }

    void bfs(vector<vector<int>>& heights, queue<pair<int, int>> &isl, vector<vector<bool>> &visPacific){
        int dirs[][2] = {{0,-1}, {0, 1}, {-1, 0}, {1, 0}};

        int m = heights.size();
        int n = heights[0].size();

        while(!isl.empty()){
            int x = isl.front().first;
            int y = isl.front().second;
            isl.pop();
            visPacific[x][y] = true;

            for(int i = 0; i<4; i++){
                int xx = x + dirs[i][0];
                int yy = y + dirs[i][1];

                if(isValid(xx, yy, m, n) && !visPacific[xx][yy] && heights[xx][yy] >= heights[x][y]){
                    isl.push({xx, yy});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> visPacific(m, vector<bool> (n));
        vector<vector<bool>> visAtlantic(m, vector<bool> (n));

        // Using BFS

        queue<pair<int, int>> pac;
        queue<pair<int, int>> atl;

        for(int i=0; i<m; i++){
            pac.push({i, 0});
            atl.push({i, n-1});
        }

        for(int j=0; j<n; j++){
            pac.push({0, j});
            atl.push({m-1, j});
        }

        bfs(heights, pac, visPacific);
        bfs(heights, atl, visAtlantic);

        // DFS Code

        // for(int i=0; i<m; i++){
        //     dfs(heights, visPacific, i, 0);
        //     dfs(heights, visAtlantic, i, n-1);
        // }

        // for(int j = 0; j<n; j++){
        //     dfs(heights, visPacific, 0, j);
        //     dfs(heights, atlvisAtlanticantic, m-1, j);
        // }

        vector<vector<int>> ans;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visPacific[i][j] && visAtlantic[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }
};