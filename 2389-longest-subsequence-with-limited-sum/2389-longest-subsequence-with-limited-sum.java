class Solution {
    
    static int binarySearch(int [] prefix, int target) {
        int l=0, r = prefix.length-1;
        int ans=-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(prefix[mid]==target) return ans = mid;
            else if(prefix[mid]>target && mid>l && prefix[mid-1]<target) {
                ans = mid-1;
                r=mid-1;
            }
            
            else if(prefix[mid]<target) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
  }
    public int[] answerQueries(int[] nums, int[] queries) {
        int n = nums.length;
        int m = queries.length;
        Arrays.sort(nums);
        
        int []ans =  new int[m];
        int []prefix = new int[n];
        
        prefix[0] = nums[0];
        
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        for(int i=0; i<m; i++){
            int idx = binarySearch(prefix, queries[i]);
            ans[i] = idx == -1? 0: idx+1;
        }
        
        return ans;
    }
}