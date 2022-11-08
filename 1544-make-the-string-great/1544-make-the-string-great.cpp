class Solution {
public:
    string makeGood(string s) {
        if(s.size()==1) return s;
        stack<char> st;
        
        st.push(s[0]);
        int n=s.size();

        for(int i=1; i<n; i++){
            if(st.empty()) st.push(s[i]);
            else if(st.top()== s[i]+32 ||st.top()== s[i]-32){
                st.pop();
            } else{
                st.push(s[i]);
            }
        }
        
        string ans = "";
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};