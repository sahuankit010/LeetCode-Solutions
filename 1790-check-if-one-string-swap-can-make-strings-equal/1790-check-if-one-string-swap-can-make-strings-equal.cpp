class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)  return true;
        int count=0;
        for(int i=0; i<s1.length(); i++){
            if(s1[i]!=s2[i])    count++;
        }
        if(count>2) return false;
        else{
            int arr[26] ={0};
            for(int i=0; i<s1.length(); i++){
                arr[s1[i]-'a']++;
                arr[s2[i]-'a']--;
            }
            for(int i=0; i<26; i++)
                if(arr[i]!=0)   return false;    
        }
        return true;
    }
};