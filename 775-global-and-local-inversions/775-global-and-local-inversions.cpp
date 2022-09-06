class Solution {
public:
    
    int countandMerge(vector<int> nums, int l, int m , int r){
        
        int n1 = m-l+1, n2 = r-m;
        
        vector<int> left, right;
        
        for(int i=0;i<n1;i++){
            left.push_back(nums[l+i]);
        }
        
        for(int i=0;i<n2;i++){
            right.push_back(nums[m+1+i]);
        }
        
        int res = 0, k = l, i=0, j=0;
        
        while(i<n1 && j< n2){
            
            if(left[i] <= right[j]){
                nums[k++] = left[i++];
            } else {
                nums[k++] = right[j++];
                res+= n1-i;
            }
        }
        
        while(i<n1) nums[k++] =left[i++];
        while(j<n2) nums[k++]= right[j++];
        return res;
    }
    
    int countGlobalInversion(vector<int> nums, int l, int r){
        
        int res = 0;
        
        if(l<r){
            int m = l + (r-l)/2;
            
            res+= countGlobalInversion(nums, l, m);
            res+= countGlobalInversion(nums, m+1, r);
            res+= countandMerge(nums, l, m , r);
        }
        
        return res;
    }
    bool isIdealPermutation(vector<int>& A) {
        for(int i = 0 ; i < A.size() ; i++){
            if(abs(A[i] - i) > 1)
                return false;
        }
        return true;
    }
};