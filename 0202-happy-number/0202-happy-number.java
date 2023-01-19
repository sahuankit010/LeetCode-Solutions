class Solution {
    public boolean isHappy(int n) {
        Set<Integer> hs = new HashSet<>();
        
        while(n!=1){
            if(hs.contains(n)) return false;
            hs.add(n);
            n = sumOfSquares(n);
            
        }
        return true;
    }
    
    int sumOfSquares(int n){
        int num = 0;
        
        while(n>0){
            
            int rem = n%10;
            num += rem*rem;
            n /= 10;
        }
        System.out.println(num);
        return num;
    }
}