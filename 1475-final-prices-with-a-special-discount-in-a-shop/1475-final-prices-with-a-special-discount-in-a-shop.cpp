class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>answer;
        int n=prices.size();
        for(int i=0; i<n-1; i++){
            int curr=prices[i];
            bool flag = false;
            for(int j=i+1; j<n; j++){
                if(prices[j]<=curr){
                    answer.push_back(curr-prices[j]);
                    flag = true;
                    break;
                }
            }
            
            if(!flag){
                answer.push_back(curr);
            }
        }
        
        answer.push_back(prices[n-1]);
        
        return answer;
    }
};