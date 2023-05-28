class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26]={0};
        
        for(char c: s){
            arr[c - 97]++;
        }
        for(char c: t){
            arr[c - 97]--;
        }
        
        for(int i=0; i<26; i++){
            if(arr[i]!=0) return false;
        }
        
        return true;
    }
};