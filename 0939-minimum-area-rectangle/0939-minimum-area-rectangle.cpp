class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        int minArea = INT_MAX;
        unordered_map<int, unordered_set<int>> mapFromXToY;

        for(vector<int> &temp: points){
            mapFromXToY[temp[0]].insert(temp[1]);
        }

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){

                int x1 = points[i][0], y1 = points[i][1]; // A
                int x2 = points[j][0], y2 = points[j][1]; // B

                if(x1 != x2 && y1 != y2){
                    if(mapFromXToY[x1].count(y2) && mapFromXToY[x2].count(y1)){
                        minArea = min(minArea, abs(x1-x2) * abs(y1-y2));
                    }
                }
            }
        }

        return minArea != INT_MAX? minArea : 0;
    }
};