class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int ans = tickets[k];
        
        for(int i=0;i<n; i++){
            if(i<k){
                if(tickets[i]<=tickets[k])
                    ans += tickets[i];
                else
                    ans += tickets[k];
            } else if(i>k){
                if(tickets[i]<tickets[k]) ans += tickets[i];
                else ans += tickets[k]-1;
            }
        }
        return ans;
    }
};