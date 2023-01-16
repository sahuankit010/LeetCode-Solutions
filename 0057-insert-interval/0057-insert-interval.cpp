class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        int n = intervals.size();
        if(n==0) {
            ans.push_back(newInterval);
            return ans;
        }   
        for (int i = 0; i < intervals.size(); i++){
            if (intervals[i][1] < newInterval[0]){
                ans.push_back(intervals[i]);
            }
			// the new interval's range is before the other, so we can add the new interval and update it to the current one
            else if (intervals[i][0] > newInterval[1])
            {
                ans.push_back(newInterval);
                newInterval = intervals[i]; 
            }
			// the new interval is in the range of the other interval, we have an overlap, so we must choose the min for start and max for end of interval 
            else if(intervals[i][1] >= newInterval[0] || intervals[i][0] <= newInterval[1])
            {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);

            }
        }
        ans.push_back(newInterval); 
        return ans;
    }
};