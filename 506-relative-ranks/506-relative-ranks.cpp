class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int,int> > pq;// max heap
        for(int i=0;i<nums.size();i++){
            pq.push(make_pair(nums[i],i));
        }
        vector<string> rank(nums.size(),"");
        int count = 1;
        for (int i=0; i<nums.size(); i++) {
            pair<int,int> p = pq.top();
            pq.pop();
            if (i==0) rank[p.second] = "Gold Medal";
            else if (i==1) rank[p.second] = "Silver Medal";
            else if (i==2) rank[p.second] = "Bronze Medal";
            else rank[p.second] = to_string(i+1);
        }
        
        return rank;
    }
};