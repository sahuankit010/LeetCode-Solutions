#define ll long long
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        ll mini=INT_MAX;
        int n=nums.size();
        vector<ll>left(n,0);
        vector<ll>right(n,0);
            
        left[0]=nums[0];
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+nums[i];
        }
        right[n-1]=0;
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]+nums[i+1];
        }
        ll ind;
        for(int i=0;i<n;i++){
            ll avg1=left[i]/(i+1);
            ll avg2=0;
            if(n-i-1>0)
                avg2=right[i]/(n-i-1);
            ll s=abs(avg1-avg2);
            if(mini>s){
                mini=s;
                ind=i;
            }
        }
        return ind;
    }
};