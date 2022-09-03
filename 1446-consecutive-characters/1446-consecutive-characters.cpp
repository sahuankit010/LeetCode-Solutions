class Solution {
public:
    int maxPower(string s) {
        char a = s[0];
        int ans = 1;
        int curr = 1;
        for(int i=1;i<s.size();i++){
            if(a==s[i]){
                curr++;
                a=s[i];
                ans = max(ans,curr);
            }
            else{
                curr = 1;
                a = s[i];
            }
            ans = max(ans,curr);
        }
            
        return ans;
        }
};