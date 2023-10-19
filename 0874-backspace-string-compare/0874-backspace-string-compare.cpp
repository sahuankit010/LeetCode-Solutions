class Solution {
public:
    string f(string &str){
        string temp = "";
        stack<char> st;

        for(int i=0; i<str.size(); i++){
            if(str[i] == '#' && st.size()>=1) st.pop();
            else if(str[i]!='#') st.push(str[i]);
        }
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        } 
        cout<<temp<<endl;
        return temp;
    }
    bool backspaceCompare(string s, string t) {
        string s1 = f(s);
        string s2 = f(t);
        return s1 == s2;
    }
};