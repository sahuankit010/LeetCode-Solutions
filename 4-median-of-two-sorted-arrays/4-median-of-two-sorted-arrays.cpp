class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        
        int i=0, j=0;
        int m = nums1.size(), n = nums2.size();
        
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]) temp.push_back(nums1[i++]);
            else temp.push_back(nums2[j++]);
        }
        while(i<m) temp.push_back(nums1[i++]);
        while(j<n) temp.push_back(nums2[j++]);
        for(int x: temp) cout<<x<<" ";
        cout<<endl;
        int siz = temp.size();
        return siz%2==1? double(temp[siz/2]) : (double(temp[siz/2])+ double(temp[(siz-1)/2]))/2;
    }
};