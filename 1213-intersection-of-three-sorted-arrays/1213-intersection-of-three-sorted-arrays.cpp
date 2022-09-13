class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
            unordered_map<int,int>m;
			for(int i=0;i<arr1.size();i++)
				m[arr1[i]]++;
			for(int i=0;i<arr2.size();i++)
				m[arr2[i]]++;
			for(int i=0;i<arr3.size();i++)
				m[arr3[i]]++;
			vector<int>ans;
			for(auto j : m){
				if(j.second==3)
					ans.push_back(j.first);
			}
			sort(ans.begin(),ans.end());
			return ans;
    }
};