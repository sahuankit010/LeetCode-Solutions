class Solution {
public:
    bool checkIfPangram(string sentence) {
        int arr[26]={0};
        
        for(char c: sentence){
            arr[c - 97]++;
        }
        
        for(int i = 0; i<26; i++)
            if(arr[i]<1) return false;
        return true;
    }
};