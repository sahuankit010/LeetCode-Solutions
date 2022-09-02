class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int res = 0;
        int depth = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                depth++;
            } else if(s[i]==')'){
                depth--;
            } 
            res = max(res, depth);
        }
        return res;
    }
};