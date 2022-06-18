class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++){
            
            int left = 0, right = matrix[i].size()-1;
            
            if(matrix[i][right]<target) continue;
            else if(matrix[i][right]>target) {
                for(int j = left; j<=right; j++){
                    if(matrix[i][j]==target) return true;
                }
            }
            
            if(matrix[i][right]==target) return true;
        }
        
        return false;
    }
};