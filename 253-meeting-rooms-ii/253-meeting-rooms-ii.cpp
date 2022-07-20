class Solution {
public:
    
    static bool myComp(vector<int>v1, vector<int>v2){
        if(v1[0]<v2[0]) return true;
        if(v1[0]==v2[0]) return v1[1]<v2[1];
        return false;
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), myComp);
        int ans = 1;
        priority_queue< int, vector<int>, greater<int> > meetings;
        meetings.push(intervals[0][1]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=meetings.top())
                meetings.pop();
            meetings.push(intervals[i][1]);
        }
        return meetings.size();
    }
};