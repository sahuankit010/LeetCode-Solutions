//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int minimumCost(int cost[], int n, int W) 
	{ 
        // Your code goes here
        int t[n+1][W+1];
        
        for(int i=0; i<W+1; i++) t[0][i] = 100000;
        for(int j=0; j<n+1; j++) t[j][0] = 0;
        
        
        
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<W+1; j++){
                if(cost[i-1]!=-1 && j-i>=0){
                    t[i][j] = min(t[i-1][j],  cost[i-1]+ t[i][j-i]);
                } else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][W];
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends