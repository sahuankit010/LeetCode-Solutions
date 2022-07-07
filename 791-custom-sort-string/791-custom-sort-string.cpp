class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        unordered_map<char,int>ump;
        
        for(char c: s) ump[c]++;
        
        for(char c: order){
            if(ump.find(c)!=ump.end()){
                for(int i=0;i<ump[c];i++){
                    ans+=c;
                }
            }
            ump[c] = 0;
        }
        
            for(auto c:ump){
                if(c.second!=0){
                    for(int i=0;i<c.second;i++){
                        ans+=c.first;
            }
        }
    }
        
        return ans;
    }
};