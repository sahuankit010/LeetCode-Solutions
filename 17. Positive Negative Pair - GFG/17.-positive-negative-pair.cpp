// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
#include <unordered_map>
#include <math.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) 
    {
        // code here
        unordered_set<int>h(arr,arr+n);
        h.erase(0);
        vector<int>vec,vec1;
        vec1.push_back(0);
        for(int i=n-1;i>=0;i--){
            if(h.find(-arr[i])!=h.end()){
                if(arr[i]>0){
                    vec.push_back(arr[i]);
                    vec.push_back(-arr[i]);
                } else{
                    vec.push_back(-arr[i]);
                    vec.push_back(arr[i]);
                }
                h.erase(arr[i]);
            }
        }
        reverse(vec.begin(), vec.end());
        return vec.size()? vec : vec1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        vector <int> res = obj.findPairs(arr, n);
    	if(res.size()!=0)
    	{
    		for (int i : res) 
            	cout << i << " ";
        	cout << endl;	
    	}
    	else
    		cout<<0<<endl;
    }

    return 0;
}  // } Driver Code Ends