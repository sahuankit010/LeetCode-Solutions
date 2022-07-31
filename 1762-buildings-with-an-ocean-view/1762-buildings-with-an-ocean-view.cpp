class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int>ans;
        int n=heights.size();
        stack<pair<int,int>>s;
        for(int i=0;i<n;i++){
            s.push({i,heights[i]});
        }
        
        int maxi = s.top().second;
        ans.push_back(s.top().first);
        s.pop();
        while(!s.empty()){
            if(maxi<s.top().second){
                maxi = s.top().second;
                ans.push_back(s.top().first);
            }
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};