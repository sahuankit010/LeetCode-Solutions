class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> str {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_map<char,string> hm;
        
        for(int  i = 97;i<123;i++){
            hm[char(i)]=str[i-97];
        }
        
        unordered_map<string,int> ans;
        
        for(int i=0;i<words.size();i++){
            string st1="";
            for(int j=0;j<words[i].length();j++){
                st1= st1+ hm[words[i][j]];
            }
            ans[st1]++;
        }
        
        return ans.size();
    }
};