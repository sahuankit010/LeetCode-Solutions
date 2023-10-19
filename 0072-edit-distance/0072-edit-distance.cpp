class Solution {
public:
// converting word1 to word2
// through insertion, deletion, and substitution
    int f(string &word1, string &word2, int n1, int n2, vector<vector<int>> &memo){

        if(n1==0) return n2;
        if(n2==0) return n1;

        if(memo[n1][n2]!=-1) return memo[n1][n2];

        if(word1[n1-1] == word2[n2-1]) return f(word1, word2, n1-1, n2-1, memo);

        else {
            int insertion = f(word1, word2, n1, n2 - 1, memo);
            int deletion = f(word1, word2, n1 - 1, n2, memo);
            int substitution = f(word1, word2, n1 - 1, n2 - 1, memo);
            return memo[n1][n2] = 1 + min(insertion, min(deletion, substitution));
        }
        // return 1 + min(f(word1, word2, n1-1, n2), min(f(word1, word2, n1, n2-1), f(word1, word2, n1-1, n2-1)));
    }
    int minDistance(string word1, string word2) {

        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector<int>> memo(n1+1, vector<int> (n2+1, -1));

        return f(word1, word2, n1, n2, memo);
    }
};