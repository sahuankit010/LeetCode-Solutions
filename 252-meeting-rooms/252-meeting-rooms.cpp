class Solution {
public:
    static bool myComp(vector<int>v1, vector<int>v2){
        if(v1[1]<v2[1]) return true;
        if(v1[1]==v2[1]) return v1[0]<v2[1];
        return false;
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), myComp);
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i-1][1]>intervals[i][0]) return false;
        }
        
        return true;
    }
};