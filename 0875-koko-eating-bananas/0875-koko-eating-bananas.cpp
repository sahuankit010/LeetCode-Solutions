class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int ans=INT_MAX, n= piles.size();
        int r = *max_element(piles.begin(), piles.end());
        int l=1;
        while(l<=r){
            int mid = r+(l-r)/2;
            int sum=0;
            for(int j=0; j<n; j++){
                int d=0, rem=0;
                d = piles[j]/mid;
                rem = piles[j]%mid;
                
                if(rem>0)
                    d++;
                sum+=d;
                
            }
            if(sum<=h){
                ans = min(ans, mid);
                r= mid-1;
            }else{
                l=mid+1;
            }
               
        }
        return ans;
    }
};