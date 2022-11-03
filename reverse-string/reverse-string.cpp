class Solution {
public:
    void fun(vector<char> &s, int l, int r){
        
        if(l>r) return;
        swap(s[l++],s[r--]);
        fun(s,l,r);
    }
    void reverseString(vector<char>& s) {
        
        fun(s,0,s.size()-1);
    }
};