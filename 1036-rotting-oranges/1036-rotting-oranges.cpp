class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        int minutes = -1, freshOranges = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(grid[i][j] == 2) q.push({i, j});
                    
                if(grid[i][j] == 1) freshOranges++;
            }
        }

        if(freshOranges == 0) return 0;

        if(q.empty()) return -1;

        int dirs[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty()){
            
            int size = q.size();

            while(size--){
                
                auto it  = q.front();
                q.pop();

                for(int k = 0; k<4; k++){

                    int x = dirs[k][0] + it.first;
                    int y = dirs[k][1] + it.second;

                    if((x >= 0 && x < m && y >= 0 && y < n) && grid[x][y] == 1){
                        freshOranges--;
                        q.push({x, y});
                        grid[x][y] = 2;
                    
                    }
                }
            }
            
            minutes++;
        }

        if(!freshOranges) return minutes;
        return -1;
    }
};