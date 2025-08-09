class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for(int &num: nums){
            map[num]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto &[key, val]: map){
            pq.push({val, key});
        }

        vector<int> ans;
        int i=0;
        while(i<k){
            pair<int, int> p = pq.top();
            ans.push_back(p.second);
            pq.pop();
            i++;
        }

        return ans;
    }
};