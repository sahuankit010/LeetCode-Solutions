class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        sort(jobs.begin(),jobs.end());
        sort(workers.begin(),workers.end());
        int n = jobs.size();
        int ans = 0;
        for(int i=0;i<n; i++){
            int q = jobs[i]/workers[i];
            int rem = jobs[i]%workers[i];
            if(rem!=0) q++;
            ans = max(q, ans);
        }
        return ans;
    }
};