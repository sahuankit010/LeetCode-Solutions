class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        int r = 0,c = n - 1;
        int last = n;
        while(r<m){
            while(c>=0 and grid[r][c] < 0){
                last = c;
                c--;   
            }
            ans+= (n-last);
            r++;
        }
        return ans;
    }
};