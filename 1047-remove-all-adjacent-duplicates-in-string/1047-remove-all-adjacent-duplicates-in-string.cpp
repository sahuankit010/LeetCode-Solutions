class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        st.push(s[0]);
        int i=1;
        while(i<s.length()){
            if(st.empty() or st.top()!=s[i]){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
            i++;
        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};