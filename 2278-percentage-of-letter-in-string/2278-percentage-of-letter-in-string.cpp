class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n=s.length(), count=0;
        for(char c: s)
            if(letter==c) count++;
        count*=100;
        // cout<<count;
        return round(count/n);
    }
};