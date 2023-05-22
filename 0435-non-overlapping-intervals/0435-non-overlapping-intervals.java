class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0]-b[0]);
        
        int ans = 0;
        
        // for(int i=0; i<intervals.length; i++){
        //     System.out.println(intervals[i][0]+","+intervals[i][1]);
        // }
        int pre = 0;
        for(int i=1; i<intervals.length; i++){
            if(intervals[i][0] < intervals[pre][1]){
                ans++;
                if(intervals[i][1] < intervals[pre][1]) pre = i;
            }
            else pre = i;
        }
        
        return ans;
    }
}