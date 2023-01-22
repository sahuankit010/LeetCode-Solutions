class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
       
        if(strs.size()==1) return strs[0];
        string res="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        
        int n=strs.size();
        
         for(int i=0;i<n;i++){
             if(strs[i].size()==0) return "";
         }
        bool flag = true;
        for(int i=0;i<n-1;i++){
            if(strs[i]!=strs[i+1]) flag = false;
         }
        if(flag) return strs[0];
        
        for(int i=0;i<n-1;i++){
            
            string ans="";
            int j=0;
            
            while(strs[i][j]==strs[i+1][j] and j<strs[i+1].size()){
                ans+=strs[i][j];
                j++;
            }
            
            if(ans<res or ans.size()<res.size()){
                res=ans;
            }
        }
        
        return res;
    }
};