class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /*
        1. Put all the elements of num2 in a hashmap ({nums2[i], i}).
        2. Iterate nums1 from i to n i++
        3. get index j of nums1 in nums2
        4. go to right side of nums2 from j to n and if greater put this in answer
            vector else -1;
        5. return ans;
        */

        int n = nums1.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> map;
        stack<int> st;

        for(int i=0; i<nums2.size(); i++){
            while(!st.empty() && st.top()<nums2[i]){
                map[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        for(int i = 0; i<n; i++){
            if(map.count(nums1[i])) ans[i] = map[nums1[i]];
        }

        return ans;
    }
};