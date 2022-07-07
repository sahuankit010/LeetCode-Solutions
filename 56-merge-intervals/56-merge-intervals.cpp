class Solution {
public:
    
    // static bool myComp(int p1[],int p2[]){
    //     return p1[0]<=p2[0];
    // }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        sort(intervals.begin(),intervals.end());
        
        // for(int i=0;i<intervals.size();i++){
        //     cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        // }
        res.push_back(intervals[0]);
        int q=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=res[q][1]){
                res[q][0] = min(res[q][0],intervals[i][0]);
                res[q][1] = max(res[q][1],intervals[i][1]);
            } else{
                res.push_back(intervals[i]);
                q++;
            }
        }    
        return res;    
    }
};