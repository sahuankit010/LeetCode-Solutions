class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<pair<int, vector<int>>> vec;
        
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            int curr = nums[i];
            int temp = curr;
            vector<int> tv;
            while(temp>0){
                
                tv.push_back(temp%10);
                temp/=10;
                
            }
            
            sort(begin(tv), end(tv));
            
            vec.push_back({curr, tv});
        }
        int ans = INT_MIN;
        
        for(int i=0; i<n-1; i++){
            
            pair<int,vector<int>> currPairI = vec[i];
            int len1 = currPairI.second.size();
            
            for(int j=i+1; j<n; j++){
                pair<int,vector<int>> currPairJ = vec[j];
                int len2 = currPairJ.second.size();
                
                if((currPairI.first + currPairJ.first) > ans && currPairI.second[len1-1] == currPairJ.second[len2-1]){
                    ans = currPairI.first + currPairJ.first;
                }
            }                 
                
        }
        
        return ans != INT_MIN? ans : -1;
    }
};