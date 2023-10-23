class Solution {
public:
    // int arr[5001][5001][51];
    int mod = 1e9 + 7;
    int recur(int i, int j, int m, int n, int sum, vector<vector<int>> &grid, int k, vector<vector<vector<int>>> &memo){

        if(i>=m || j>=n) return 0;

        else if(i == m-1 && j == n-1 && (sum + grid[i][j]) % k == 0) return 1;

        else if(memo[i][j][sum]!=-1) return memo[i][j][sum]%mod;

        else{
            int down = recur(i+1, j, m, n, (sum + grid[i][j])%k, grid, k, memo)%mod;
            int right = recur(i, j+1, m, n, (sum + grid[i][j])%k, grid, k, memo)%mod;

            return memo[i][j][sum] = (down+right)%mod;
        }


    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        // memset(arr, -1, sizeof(arr));
        vector<vector<vector<int>>> memo(m+1, vector<vector<int>> (n+1, vector<int> (k+1, -1)));

        return recur(0, 0, m, n, 0, grid, k, memo);
    }
};