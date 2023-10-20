class Solution {
public:
    void f(int n, int l, int r, string paren, vector<string> &ans){
        if(l==n && r==l) ans.push_back(paren);
        else{
            if(l<n){
                f(n,l+1, r, paren + '(', ans);
            } if(r<l){
                f(n,l, r+1, paren + ')', ans);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string paren = "";

        f(n,0,0,paren, ans);
        return ans;
    }
};