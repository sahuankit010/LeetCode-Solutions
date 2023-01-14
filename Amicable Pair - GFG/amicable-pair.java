//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S[] = read.readLine().split(" ");
            
            int A = Integer.parseInt(S[0]);
            int B = Integer.parseInt(S[1]);

            Solution ob = new Solution();
            System.out.println(ob.isAmicable(A,B));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    static int isAmicable(int A , int B) {
        // code here
        if(A==B) return 0;
        int s1 = 1, s2 = 1;
        
        for(int i=2; i<=Math.sqrt(A); i++)
            if(A%i==0) s1 += i + A/i;
        
        for(int i=2; i<=Math.sqrt(B); i++)
            if(B%i==0) s2 += i + B/i; 
        
        return (s1 == B) && (s2 == A)? 1: 0;    
    }
};