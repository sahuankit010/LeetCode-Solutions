class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        if(columnNumber<=25){
            char c = char(columnNumber+64);
            ans+=c;
                
        } else{
            while(columnNumber){
                columnNumber--;
                ans += char(columnNumber%26+'A');
                columnNumber /= 26;
            }
            reverse(begin(ans), end(ans));
        }
        return ans;
    }
};