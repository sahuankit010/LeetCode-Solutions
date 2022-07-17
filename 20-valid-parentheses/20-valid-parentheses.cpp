class Solution {
public:
    bool isValid(string s) {
        if(s.length()==1) return false;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else if(!st.empty()){
                if((s[i]==')' and st.top()=='(') ||
                  (s[i]=='}' and st.top()=='{') ||
                  (s[i]==']' and st.top()=='[')) {
                    st.pop();
                } else return false;
            } else return false;
        }
        
        return st.empty();
    }
};