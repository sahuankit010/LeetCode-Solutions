class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        
        Map<Integer, Integer> hm = new HashMap<>();
        
        for(int i=0; i<arr.length; i++){
            hm.put(arr[i], hm.getOrDefault(arr[i], 0) + 1);
        }
        
        List<Integer> l = new ArrayList<>();
        
        for(Map.Entry<Integer, Integer> e: hm.entrySet()){
            l.add(e.getValue());
        }
        
        Collections.sort(l);
        
        for(int i=0; i<l.size(); i++){
            int val = l.get(i);
            if(k>=val){
                k -= val;
                l.set(i, 0);
            } else{
                l.set(i, val);
                k=0;
                break;
            }
        }
    
        int ans = 0;
        
         for(int i=0; i<l.size(); i++){
             if(l.get(i)>0) ans++;
         }
        
        return ans;
    }
}