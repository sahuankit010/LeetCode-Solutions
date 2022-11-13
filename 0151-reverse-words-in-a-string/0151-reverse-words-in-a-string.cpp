class Solution {
public:
    string reverseWords(string s) {
        int i=0, j=s.size()-1;
        
        while(s[i]==' ') i++;
        while(s[j]==' ') j--;
        
        vector<string> temp;
        
        while(i<=j){
            string str="";
            
            while(s[i]!=' ' && i<=j){
                str += s[i];
                i++;
            }
            temp.push_back(str);
            
            while(s[i]==' ' && i<=j){
                i++;
            }
        }
        
        string ans = "";
        
        int n=temp.size();
        for(int k=n-1; k>=0; k--){
            ans += temp[k];
            if(k>0) ans+=' ';
        }
        
        return ans;
    }
};