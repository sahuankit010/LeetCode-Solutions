class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
//         map<int,int> ump;
//         for(int i=0; i<logs.size(); i++){
//             for(int j=logs[i][0]; j<logs[i][1]; j++){
//                 ump[j]++;
//             }
//         }
//         int maxi = -1;
//         int ans = -1;
        
//         for(auto x: ump){
//             if(maxi<x.second){
//                 ans = x.first;
//                 maxi = x.second;
//             }
//         }
//         return ans;
        
        vector<int>vec(2051,0);
        
        for(int i=0;i<logs.size(); i++){
            vec[logs[i][0]] += 1;
            vec[logs[i][1]] -= 1;
        }
        
        for(int i=2; i<2051; i++){
            vec[i] += vec[i-1];
        }
        
        int maxi = -1, ans=-1;
        
        for(int i=1; i<2051; i++){
            if(maxi<vec[i]){
                maxi = vec[i];
                ans = i;
            }
        }
        
        return ans;
    }
};