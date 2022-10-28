class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> ump;
        
        for(int i=0; i<logs.size(); i++){
            for(int j=logs[i][0]; j<logs[i][1]; j++){
                ump[j]++;
            }
        }
        
        int maxi = -1;
        int ans = -1;
        
        for(auto x: ump){
            if(maxi<x.second){
                ans = x.first;
                maxi = x.second;
            }
        }
        
        return ans;
    }
};