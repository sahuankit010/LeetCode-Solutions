class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        Queue<int[]> q = new ArrayDeque<>();

        int freshOrange = 0;

        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1) freshOrange++;
                else if(grid[i][j] == 2) q.offer(new int[] {i, j});
            }
        }

        if(freshOrange == 0) return 0;
        if(q.isEmpty()) return -1;

        int minutes = -1;

        int[][] dirs = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.isEmpty()){
            
            int size = q.size();

            while(size-->0){

                int[] curr = q.poll();

                for(int k = 0; k<4; k++){
                    int x = dirs[k][0] + curr[0];
                    int y = dirs[k][1] + curr[1];

                    if(x>=0 && x<m && y>=0 && y<n && grid[x][y] == 1){
                        freshOrange--;
                        q.offer(new int[] {x,y});
                        grid[x][y] = 2;
                    }
                }
            }
            minutes++;
        }

        return (freshOrange != 0) ? -1 : minutes;
        
    }
}