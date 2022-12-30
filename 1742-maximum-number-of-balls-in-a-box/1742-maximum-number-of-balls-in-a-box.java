class Solution {
    public int countBalls(int lowLimit, int highLimit) {
        
         HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();    
        
        for(int i=lowLimit; i<=highLimit; i++){
            int s = getSum(i);
            
            if(map.containsKey(s)){
                map.put(s, map.get(s) + 1);
            } else{
                map.put(s, 1);
            }
        }
        int ans = Integer.MIN_VALUE;
        for(int freq: map.values()) {
            ans = Math.max(ans, freq);
        }
        
        return ans;
    }
    
    public int getSum(int num){
        int sum=0;
        while(num>0){
            sum += num%10;
            num /= 10;
        }
        
        return sum;
    }
}