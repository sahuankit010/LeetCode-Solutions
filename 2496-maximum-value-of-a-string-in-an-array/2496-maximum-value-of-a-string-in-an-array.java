class Solution {
    public int maximumValue(String[] s) {
        int p=0;
        for(String k:s){
            int m=0,d=0,f=0;
            for(char c:k.toCharArray()){
                if(c>='a' && c<='z'){
                    m++;
                } else if(c>='0' && c<='9'){
                    d++;
                    f=f*10+(c-'0');
                }
            }
            if(m>0 && d>0){
                p=Math.max(p,k.length());
            }else if(m==0){
                p=Math.max(p,f);
            } else if(d==0){
                p=Math.max(p,k.length());
            }
        }
        return p;
    }
}