class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> ump;
        for(int i=0; i<arr.size(); i++){
            ump[arr[i]]++;
        }
        unordered_set<int> us;
        
        for(auto x: ump){
            us.insert(x.second);
        }
        
        return ump.size()==us.size();
    }
};