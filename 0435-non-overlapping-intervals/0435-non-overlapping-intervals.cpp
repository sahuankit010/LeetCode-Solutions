class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int cnt=0;
        int pre = 0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] < intervals[pre][1]){
                cnt++;
                if(intervals[i][1] < intervals[pre][1]) pre = i;
            }
            else pre = i;
        }
        return cnt;
    }
};