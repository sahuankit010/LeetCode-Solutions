class Solution {
    public int largestOverlap(int[][] A, int[][] B) {
        int n = A.length;
        List<Pair<Integer, Integer>> va, vb = new ArrayList<>();
        va = fun(A);
        vb = fun(B);
        
        HashMap<Pair<Integer, Integer>, Integer> hm = new HashMap<Pair<Integer, Integer>, Integer>();
        
        for(Pair<Integer, Integer> px: va){
            for(Pair<Integer, Integer> py: vb){
                int x = py.getKey() - px.getKey();
                int y = py.getValue() - px.getValue();
                Pair <Integer, Integer> p  = new Pair<Integer, Integer> (x,y);
                hm.put(p, hm.getOrDefault(p, 0) + 1);
            }
        }
        int ans = 0;
        for(Map.Entry<Pair<Integer, Integer>, Integer> e : hm.entrySet()){
            ans = Math.max(ans, e.getValue());
        }
        return ans;
    }
    
    public List<Pair<Integer, Integer>> fun(int [][]A){
        List<Pair<Integer, Integer>> ones = new ArrayList<>();
        int n=A.length;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(A[i][j]==1) ones.add(new Pair <Integer,Integer>(i,j));
            }
        }
        return ones;
    }
}