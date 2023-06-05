class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        
        st.push({s[0], 1});
        
        for(int i=1; i<s.size(); i++){
            if(!st.empty()){
                if(st.top().first == s[i]){
                    pair<char, int> topPair = st.top();
                    st.push({s[i], topPair.second + 1});
                } else{
                    st.push({s[i], 1});
                }
            } else{
                st.push({s[i], 1});
            }
            
            if(st.top().second == k){
                int count = 0;
                
                while(!st.empty() && count<k){
                    st.pop();
                    count++;
                }
            }
        }
        
        string ans = "";

        while(!st.empty()){
            ans += st.top().first;
            st.pop();
        }
        reverse(begin(ans), end(ans));
        
        return ans;
    }
};