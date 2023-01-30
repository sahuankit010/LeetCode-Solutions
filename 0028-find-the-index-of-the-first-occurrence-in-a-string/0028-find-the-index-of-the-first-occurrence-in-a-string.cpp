class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.length();
        int m = needle.length();
        
        if(n==1){
            if(haystack[0] == needle[0])
                return 0;
        }
        for(int i=0; i <= n-m;){
            int j=0;
            for(;j<m;j++){
                if(needle[j] != haystack[i+j]) break;
            }
            cout<<i<<" ";
            if(j == m) return i;
            i++;
        }
        return -1;
        // int i = haystack.find(needle);
        // return i!=-1?i:-1;
    }
};