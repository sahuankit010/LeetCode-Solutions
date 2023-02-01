class Solution {
public:
    
    int solve(int idx, int prev, vector<pair<int,int>> &store, vector<vector<int>> &mem, int n){
        if(idx >= n) return 0;
        
        if(mem[idx][prev+1] != -1) return mem[idx][prev+1];
        
        int take = 0, notTake = 0;
        
        if(prev == -1 || store[idx].second >= store[prev].second){
            take = store[idx].second + solve(idx+1, idx, store, mem, n);
        }
        
        notTake = solve(idx+1, prev, store, mem, n);
        
        return mem[idx][prev+1] = max(take, notTake);
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> store;
        int n=ages.size();
        
        for(int i=0; i<n; i++){
            store.push_back({ages[i],scores[i]});
        }
        
        sort(begin(store), end(store));
        
        vector<vector<int>> mem(n,vector<int>(n+1,-1));
        /*//mem structure
        {
            0: {-1,-1,-1},
            1: {-1,-1,-1},
            2: {-1,-1,-1},
            .......... 
            ..........
        }
        */
        return solve(0, -1, store, mem, n);
    }
};
