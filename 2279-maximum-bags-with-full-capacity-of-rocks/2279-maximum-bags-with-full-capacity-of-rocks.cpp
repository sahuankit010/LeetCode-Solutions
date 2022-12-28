class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        vector<int>diff;
        int n=capacity.size();
        for(int i=0; i<n; i++){
            diff.push_back(capacity[i]-rocks[i]);
        }
        sort(begin(diff), end(diff));
        
        // for(int x: diff){
        //     cout<<x<<" "<<endl;
        // }
        // vector<pair<int,pair<int,int>> comp;
        int ans=0;
        for(int i=0; i<n; i++){
            if(diff[i]>0){
                if(additionalRocks-diff[i]>=0){
                    ans++;
                    additionalRocks-=diff[i];
                }
            } else{
                ans++;
            }
        }
        return ans;
    }
};