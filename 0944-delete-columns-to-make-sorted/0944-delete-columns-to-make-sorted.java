class Solution {
    public int minDeletionSize(String[] strs) {
        int n = strs[0].length();
        // System.out.println(n);
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<strs.length-1; j++){
                if(strs[j].charAt(i)>strs[j+1].charAt(i)) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
}