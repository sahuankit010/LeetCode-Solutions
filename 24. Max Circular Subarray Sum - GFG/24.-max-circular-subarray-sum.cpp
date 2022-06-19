// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    
    int kadaneMaxSubArraySum(int arr[], int num){
        
        int curr_sum = arr[0];
        
        int max_sum = arr[0];
        
        for(int i=1;i<num;i++){
            curr_sum=max(arr[i], arr[i]+curr_sum);
            max_sum=max(max_sum,curr_sum);
        }
        return max_sum;
    }
    
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int maxNormalSubArraySum = kadaneMaxSubArraySum(arr,num);
        
        if(maxNormalSubArraySum<0) return maxNormalSubArraySum;
        
        int arr_sum = 0;
        
        for(int i=0;i<num;i++){
            arr_sum+=arr[i];
            arr[i]=-1*arr[i];
        }
        
        int max_circular_sum = arr_sum + kadaneMaxSubArraySum(arr,num);
        
        return max(max_circular_sum, maxNormalSubArraySum);
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends