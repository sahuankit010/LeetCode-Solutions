class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> umap;
        
        for (char c: s){
            umap[c]++;
        }
        vector<int> vec;
        for(auto it: umap){
            vec.push_back(it.second);
        }
        sort(begin(vec), end(vec), greater<int>());
        set<int>se;
        int ans = 0;
        for(int i=0; i<vec.size(); i++){
            while(1){
                if(vec[i] == 0) break;
                if(se.find(vec[i])==se.end()){
                    se.insert(vec[i]);
                    break;
                } else{
                    vec[i] -= 1;
                    ans++;
                }
            }
        }
        return ans;
    }
};