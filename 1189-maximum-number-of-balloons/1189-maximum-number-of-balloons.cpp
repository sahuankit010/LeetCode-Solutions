class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>ump;
        for(char c: text) ump[c]++;
        int b = ump['b'], n=ump['n'], l = ump['l']/2, o=ump['o']/2, a=ump['a'];
        return min(b,min(n, min(l, min(o,a))));
    }
};