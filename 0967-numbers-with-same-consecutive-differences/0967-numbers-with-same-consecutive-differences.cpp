class Solution {
public:
    
    void dfs(int num, int n, int k, vector<int> &ans){
        
        if(n == 0){
            ans.push_back(num);
            return;
        }
        int lastDigit = num % 10;
        if(lastDigit>=k) dfs( 10 * num + lastDigit - k, n-1, k, ans);
        if(k && (lastDigit + k) <= 9) dfs(10 * num + lastDigit + k, n-1, k, ans);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        
        for(int d=1; d<=9; d++)
            dfs(d, n-1, k, ans);
        
        return ans;
    }
};