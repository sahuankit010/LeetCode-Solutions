class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st, star;
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(') st.push(i);
            else if(s[i] == '*') star.push(i);
            else{
                if(!st.empty()) st.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }
        
        while(!st.empty() && !star.empty()){
            if(st.top()>star.top()) return false;
            star.pop();
            st.pop();
        }
        
        return st.empty();
    }
};