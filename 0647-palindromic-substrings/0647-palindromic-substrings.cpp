class Solution {
public:
    vector<vector<int>> t;
    
    int countSubstrings(string s) {
        int n = s.size();

        int count = 0;

        t.resize(n+1, vector<int> (n+1, -1));

        for(int l=1; l<=n; l++){
            for(int i=0; i+l-1<n; i++){
                int j = i+l-1;

                if(i == j) t[i][j] = 1;

                else if(j == i+1) t[i][j] = s[i] == s[j];
                
                else t[i][j] = (s[i] == s[j] && t[i+1][j-1]);

                if(t[i][j]) count++;
            }
        }

        return count;
    }
};