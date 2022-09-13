class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        
        int count[101]={0};
        for (int i = 0; i < nums2.size(); i++) {
            count[nums2[i]]++;
        }
        sort(nums1.begin(), nums1.end());

        int prodSum = 0;
        int countIdx = 100;
        
        for (int i = 0; i < nums1.size(); i++) {
            while (count[countIdx] == 0)
                --countIdx;
            prodSum += (nums1[i] * countIdx);
            count[countIdx]--;
        }
        
        return prodSum;
    }
};