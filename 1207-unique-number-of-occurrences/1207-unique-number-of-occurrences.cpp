class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hashmap;

        for(int i: arr){
            hashmap[i]++;
        }
        unordered_set<int> seen;
        for(pair<int, int> count: hashmap){ // {key, val}
            if(seen.count(count.second)) return false;
            seen.insert(count.second);
        }
        return true;
        // TC: O(n) (with two traversal)
        // SC: O(n) (hashset and hashmap)
    }
};