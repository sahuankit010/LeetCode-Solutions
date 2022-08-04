class Solution {
public:
    int lengthOfLastWord(string s) {
        
        
        int ans=0;
        int index;
        int i=s.size()-1;
        
        for(;i>=0;){
            if(s[i]==' '){
                i--;
            } else break;
        }
        
        index=i;
        
        for(int j=index;j>=0;j--){
            if(s[j]==' '){
                break;
            }
            ans++;
        }
        
        return ans;
    }
};