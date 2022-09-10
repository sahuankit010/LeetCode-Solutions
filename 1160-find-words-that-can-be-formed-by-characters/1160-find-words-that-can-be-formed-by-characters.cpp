class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        unordered_map<char,int> mp, temp;
        for(char c: chars){
            mp[c]++;
        }
        int ans = 0;
        for(int i=0; i<words.size(); i++){
            temp = mp;
            bool flag = true;
            for(int j=0; j<words[i].size();j++){
                temp[words[i][j]]--;
                if(temp[words[i][j]]<0){
                    flag = false;
                    break;
                }
            }
            
            if(flag) ans+= words[i].size();
        }
        return ans;
    }
};