class Solution {
public:
    int recur(string &word1, string &word2, int l1, int l2, vector<vector<int>> &memo){
        if(l1 == 0) return l2;
        if(l2 == 0) return l1;
        if(memo[l1][l2]!=-1) return memo[l1][l2];
        if(word1[l1-1] == word2[l2-1]) 
            return memo[l1][l2] = recur(word1, word2, l1-1, l2-1, memo);
        else{
            int ins = recur(word1, word2, l1, l2-1, memo);
            int del = recur(word1, word2, l1-1, l2, memo);
            int rep = recur(word1, word2, l1-1, l2-1, memo);
            
            return memo[l1][l2] = 1 + min(ins, min(del, rep));
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        return recur(word1, word2, m, n, memo);
    }
};