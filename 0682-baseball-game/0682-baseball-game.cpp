class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>st;
        // st.push(stoi(ops[0]));
        
        for(string c: ops){
            if(c=="D"){
                int curr = st.top()*2;
                st.push(curr);
            } else if(c=="C"){
                st.pop();
            } else if(c=="+"){
                int top1 = st.top(); st.pop();
                int newValue = top1+st.top();
                st.push(top1);
                st.push(newValue);
            } else{
                st.push(stoi(c));
            }
        }
        
        int ans =0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};