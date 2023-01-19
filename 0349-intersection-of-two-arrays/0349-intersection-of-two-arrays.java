class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        int n1 = nums1.length, n2 = nums2.length;
        
        HashSet<Integer> hs = new HashSet<>();
        
        for(int i: nums1){
            hs.add(i);
        }
        
        ArrayList<Integer> al = new ArrayList<>();
        
        for(int i: nums2){
            if(hs.contains(i)) {
                al.add(i);
                hs.remove(i);
            }
        }
        
        int ans[] = new int[al.size()];
        
        for(int i=0; i<al.size(); i++){
            ans[i] = al.get(i);
        }
        
        return ans;
    }
}