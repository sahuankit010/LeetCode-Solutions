class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        int n=nums.size();

        for(int i=0; i<n; i++){
            ump[nums[i]]++;
        }

        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for(auto &i: ump){
            pq.push({i.second, i.first});
            if(pq.size() > (int)ump.size() - k) {
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;

    }
};