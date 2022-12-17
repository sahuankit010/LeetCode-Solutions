class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans;
        int n=tokens.size();
        
        stack<string> s;
        for(int i=0; i<n; i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                long long b=stol(s.top());
                s.pop();
                
                long long a = stol(s.top());
                s.pop();
                
                if(tokens[i]=="+")
                    s.push(to_string(a+b));
                else if(tokens[i]=="-")
                    s.push(to_string(a-b));
                else if(tokens[i]=="*")
                    s.push(to_string(a*b));
                else
                    s.push(to_string(a/b));
            } else
                s.push(tokens[i]);
        }
        
        return stoi(s.top());
    }
};