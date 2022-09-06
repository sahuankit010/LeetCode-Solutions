class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        unordered_set<int> hm;
        
        for(int i=0; i<ranges.size(); i++)
            for(int j = ranges[i][0]; j<=ranges[i][1]; j++)
               hm.insert(j);
        
        for(int i=left; i<=right; i++){
            if(hm.find(i)==hm.end()) return false;
        }

        return true;
    }
};