class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> paranStack;
        string result = "";
        
//         Check for closing braces
        for(char c:s){
            if(c=='('){
                paranStack.push(c);
                result+=c;
            }else if(c==')'){
                if(paranStack.size()){
                    paranStack.pop();
                    result+=c;
                }
            }else{
                result+=c;
            }
        }
        
//         Remove opened braces
        int remOpen =paranStack.size();
        int l = result.length();
        for(int i=l-1;i>=0;i--){
            if(remOpen==0) break;
            if(result[i]=='('){
                result.erase(i,1);
                remOpen--;
            }
        }
        
        return result;
    }
};