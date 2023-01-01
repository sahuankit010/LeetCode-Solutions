class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // for(int i=0; i<)
        
        vector<string> words;
        for(int i=0; i<s.size();){
            int j=i;
            string temp = "";
            while(j<s.size() && s[j]!=' '){
                temp += s[j++];
            }
            words.push_back(temp);
            j++;
            i=j;
        }
        
//         for(int i=0; i<words.size(); i++){
//             cout<<words[i]<<" ";
//         }
        if(pattern.size()!=words.size()) return false;
        unordered_map<char,string> hash;
        
        hash[pattern[0]] = words[0];
        
        for(int i=1; i<pattern.size(); i++){
            
            if(hash.find(pattern[i])==hash.end()){
                hash[pattern[i]] = words[i];
            } else{
                if(hash[pattern[i]] != words[i]) return false;
            }
        }
        unordered_set<string> u;
        
        for(auto x: hash){
            if(u.find(x.second)==u.end()){
                u.insert(x.second);
            } else return false;
        }
        
        return true;
    }
};