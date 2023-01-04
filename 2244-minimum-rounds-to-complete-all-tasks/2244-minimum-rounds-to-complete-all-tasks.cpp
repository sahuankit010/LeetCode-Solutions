class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans=0;
        unordered_map<int,int> umap;
        int n = tasks.size();
        for(int i=0; i<n; i++){
            umap[tasks[i]]++;
        }
        sort(begin(tasks), end(tasks));
        for(int i=0; i<n; ){
            int count = umap[tasks[i]];
            if(count>=2){
                if(count<=5 && count%2==0 && count%3!=0){
                    umap[tasks[i]] = count-2;
                    i+=2;
                } else{
                    umap[tasks[i]] = count-3;
                    i+=3;
                }
                ans++;
            } else {
                return -1;
            }
        }
        return ans;
    }
};