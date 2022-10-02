class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> hs(s.begin(), s.end());
        sort(s.begin(), s.end(), greater<int>());
        for(char c: s){
            char ch = char(int(c) + 32);
            cout<<ch;
            if(hs.find(ch)!=hs.end()){
                
                string ans = "";
                ans += toupper(c);
                return ans;
            }
        }
        
        return "";
    }
};