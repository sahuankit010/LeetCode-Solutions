class Solution {
public:
    int strStr(string haystack, string needle) {
        // int n=haystack.length();
        // int m=needle.length();
        // for(int i=0;i<=n-m;){
        //     int j=0;
        //     for(;j<m;j++){
        //         if(needle[j]!=haystack[i+j]) break;
        //     }
        //     if(j==m) return i;
        //     else if(j==0) i++;
        //     else i=i+j;
        // }
        // return -1;
        int i = haystack.find(needle);
        return i!=-1?i:-1;
    }
};