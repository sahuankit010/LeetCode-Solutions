class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int sizeR=matrix.size(), sizeC=matrix[0].size();
        vector<int>row(sizeR,-1), col(sizeC,-1);
        
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[i].size();j++)
                if(matrix[i][j]==0){
                    row[i]=0;
                    col[j]=0;
                }
            
        for(int i=0;i<sizeR;i++)
            for(int j=0;j<sizeC;j++)
                if(row[i]==0 or col[j]==0)
                    matrix[i][j]=0;
    }
};