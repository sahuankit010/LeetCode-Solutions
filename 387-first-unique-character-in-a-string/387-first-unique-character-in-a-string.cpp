class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>h;
        for(char c:s)h[c]++;
        for(int i=0;i<s.length();i++){
            if(h[s[i]]==1) return i;
        }
        return -1;
    }
};