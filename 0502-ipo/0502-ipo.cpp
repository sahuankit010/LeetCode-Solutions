class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects;
        
        for(int i=0; i<n; i++)
            projects.push_back({capital[i], profits[i]});
        sort(begin(projects), end(projects));
        //max priority queue
        priority_queue<int> maxi;
        int i=0;
        while(k--){
            while(i<n && w>=projects[i].first){
                maxi.push(projects[i].second);
                i++;
            }
            if (maxi.empty())
                break;
            w += maxi.top();
            maxi.pop();
        }
        return w;
    }
};