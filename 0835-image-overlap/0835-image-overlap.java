class Solution {
    public int largestOverlap(int[][] A, int[][] B) {
        int n = A.length;
        int ans = 0;
        for(int i=-n+1; i<n; i++){
            for(int j=-n+1; j<n; j++){
                int count = countOverlap(A, B, i, j, n);
                ans = Math.max(ans, count);
            }
        }
        return ans;
    }
    
    public int countOverlap(int[][] A, int[][] B, int rowOffset, int colOffset, int n){
        
        int count = 0;
        
        for(int i=0; i<n; i++){
            int B_i = i + rowOffset;
            for(int j=0; j<n; j++){
                int B_j = j + colOffset;
                
                if(B_i>=n || B_i<0 || B_j>=n || B_j<0) continue;
                if(A[i][j]==B[B_i][B_j] && A[i][j]==1) count++;
                
            }
        }
        
        return count;
    }
}