class Solution {
    public int trap(int[] height) {
        int n = height.length;

        if(n==1) return 0;

        int ans = 0;

        int leftMax = 0, rightMax = 0;

        int left = 0, right = n-1;

        while(left < right){
            if(height[left] < height[right]){
                if(leftMax <= height[left]){
                    leftMax = height[left];
                } else{
                    ans += leftMax - height[left];
                }
                left++;
            } else{
                if(rightMax <= height[right]){
                    rightMax = height[right];
                }else{
                    ans += rightMax - height[right];
                }
                right--;
            }
        }

        return ans;

        // int[] leftMax = new int[n];

        // int[] rightMax = new int[n];

        // leftMax[0] = height[0];
        // rightMax[n-1] = height[n-1];

        // for(int i=1; i<n; i++){
        //     leftMax[i] = Math.max(leftMax[i-1], height[i]);
        // }

        // for(int i=n-2; i>=0; i--){
        //     rightMax[i] = Math.max(rightMax[i+1], height[i]);
        // }

        // for(int i=0; i<n; i++){
        //     ans += Math.min(leftMax[i], rightMax[i]) - height[i];
        // }

        // return ans;
    }
}