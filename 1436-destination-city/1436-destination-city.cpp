class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n=paths.size();
        unordered_map<string,string>ump;
        unordered_set<string>s;
        
        for(int i=0; i<n; i++){
            ump.insert({paths[i][0],paths[i][1]});
            s.insert(paths[i][0]);
            s.insert(paths[i][1]);
        }
        
        for(string x: s){
            if(ump.find(x)==ump.end()) return x;
        }
        return "";
    }
};