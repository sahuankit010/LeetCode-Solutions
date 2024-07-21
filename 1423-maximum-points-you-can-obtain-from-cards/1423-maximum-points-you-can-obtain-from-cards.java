class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int curr = 0;
		
		//First k elements in our window
        for(int i=0;i<k;i++) curr+=cardPoints[i];
        
        int res=curr;
        
        for(int i=k-1;i>=0;i--) {
			//We remove the last visited element and add the non-visited element from the last
            curr+=cardPoints[cardPoints.length-k+i] - cardPoints[i];
			
            //We check the maximum value any possible combination can give
			res = Math.max(res, curr);
        }
        
        return res;
    }
}