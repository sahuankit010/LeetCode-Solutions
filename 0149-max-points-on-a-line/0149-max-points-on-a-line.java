public class Solution{
    private int generateGCD(int a,int b){
        return b==0? a: generateGCD(b, a%b);
    }
    public int maxPoints(int[][] points) {
        if (points==null) return 0;
        if (points.length<=2) return points.length;
        	
        Map<Integer,Map<Integer,Integer>> map = new HashMap<Integer,Map<Integer,Integer>>();
        int result=0;
        for (int i=0;i<points.length;i++){
        	int overlap=0,max=0;
        	for (int j=i+1;j<points.length;j++){
        		int x=points[j][0]-points[i][0];
        		int y=points[j][1]-points[i][1];
        		if (x==0&&y==0){
        			overlap++;
        			continue;
        		}
        		int gcd=generateGCD(x,y);
        		if (gcd!=0){
        			x/=gcd;
        			y/=gcd;
        		}
        			
        		if (map.containsKey(x)){
        			if (map.get(x).containsKey(y)){
        				map.get(x).put(y, map.get(x).get(y)+1);
        			}else{
        				map.get(x).put(y, 1);
        			}   					
        		}else{
        			Map<Integer,Integer> m = new HashMap<Integer,Integer>();
        			m.put(y, 1);
        			map.put(x, m);
        		}
        		max=Math.max(max, map.get(x).get(y));
        	}
            result=Math.max(result, max+overlap+1);
            map.clear();
        }
        return result;    	
    }
}