class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int n = num.size();
        vector<int>ans;
        int div = 0;
        int i=n-1;
        
        for(; i>=0; i--){
            if(k>0){
                int curr = k%10;
                k/=10;
                int s = curr + num[i];
                s += div;
                if(s>=10){
                    div = s/10;
                    ans.push_back(s%10);
                } else{
                    div=0;
                    ans.push_back(s%10);
                }
            } else break;

        }
        for(;i>=0; i--){
            int s = num[i]+div;
            if(s>=10){
                div = s/10;
                ans.push_back(s%10);
            } else{
                div=0;
                ans.push_back(s%10);
            }
        }
        while(k>0){
            int rem = k%10;
            int s = rem+div;
            if(s>=10){
                div = s/10;
                ans.push_back(s%10);
            } else{
                div=0;
                ans.push_back(s%10);
            }
            k/=10;
        }
        if(div>0) ans.push_back(div);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};