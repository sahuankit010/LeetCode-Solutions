class Solution {
public:
    int xorOperation(int n, int start) {
        int ans =0;
        
        for(int count =0, i = 0; count<n; count++, i++){
            ans  ^= (start + 2 *i);
        }
        return ans;
    }
};