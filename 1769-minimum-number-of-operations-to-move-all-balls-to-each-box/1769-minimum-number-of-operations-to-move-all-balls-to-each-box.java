class Solution {
    public int[] minOperations(String boxes) {
        int n= boxes.length();
        int []ans = new int[n];
        int idx=0;
        for(int i=0; i<n; i++){
            int curr = 0;
            for(int l=0; l<i; l++){
                if(boxes.charAt(l)=='1'){
                    curr += Math.abs(l-i);
                }
            }
            
            for(int r=i+1; r<n; r++){
                if(boxes.charAt(r)=='1'){
                    curr += Math.abs(r-i);
                }
            }
            ans[i]=curr;
        }
        return ans;
    }
}