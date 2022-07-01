class Solution {
public:
    
    static bool cmp(pair<int,int>p1,pair<int,int>p2){
        return p1.second>=p2.second;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>>vec;
        for(int i=0;i<boxTypes.size();i++){
            vec.push_back({boxTypes[i][0],boxTypes[i][1]});
        }
        
        sort(vec.begin(),vec.end(),cmp);
        
        int sum=0;
        for(int i=0;i<vec.size();i++){
            if((truckSize-vec[i].first)>=0){
                sum+=vec[i].first*vec[i].second;
                truckSize=truckSize-vec[i].first;
            } else{
                sum+=truckSize*vec[i].second;
                break;
            }
        }
        return sum;
    }
};