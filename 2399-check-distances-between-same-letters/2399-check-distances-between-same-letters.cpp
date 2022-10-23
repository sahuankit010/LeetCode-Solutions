class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char,int>ump;
        int n=s.size();
        for(int i=0;i<n; i++){
            if(ump.find(s[i])==ump.end()){
                ump.insert({s[i],i});
            } else{
                if((i-ump[s[i]]-1)!=distance[s[i]-97]) return false;
            }
        }
        return true;
    }
};