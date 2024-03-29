class Solution {
    public int minimumRounds(int[] tasks) {
        Arrays.sort(tasks);
        HashMap<Integer, Integer> hmap = new HashMap<Integer, Integer>();
        int ans = 0;
        for(int i=0; i<tasks.length; i++)
            hmap.put(tasks[i], hmap.getOrDefault(tasks[i], 0) + 1);
        
        for(int i=0; i<tasks.length; ){
            int count = hmap.get(tasks[i]);
            if(count>=2){
                if(count<=5 && count%2==0 && count%3!=0){
                    hmap.put(tasks[i], count-2);
                    i += 2;
                } else{
                    hmap.put(tasks[i], count-3);
                    i += 3;
                }
                ans++;
            } else{
                return -1;
            }
        }
        return ans;
    }
}