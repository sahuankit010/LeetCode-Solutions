class Solution {
public:
    int n;
    vector<int> memo;
    unordered_set<string> set;

    int wordBreakUtil(string &s, int idx){
        if(idx >= n) return true;

        if(memo[idx] != -1) return memo[idx];

        string temp = "";

        for(int i = idx; i<n; i++){
            temp += s[i];

            if(set.count(temp)){
                if(wordBreakUtil(s, i+1)){
                    memo[i] = 1;
                    return 1;
                }
            }
        }

        return memo[idx] = 0;
    
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        memo.resize(n+1, -1);

        for(const string &str: wordDict){
            set.insert(str);
        }

        return wordBreakUtil(s, 0);
    }
};