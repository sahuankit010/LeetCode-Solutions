// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets..
    vector<vector<int>> res;

    void solve(vector<int> &nums, int ind, vector<int> temp)
    {
        if (ind > nums.size() - 1)
        {

            res.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        solve(nums, ind + 1, temp);
        temp.pop_back();
        solve(nums, ind + 1, temp);
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n){
        // code here 
     sort(arr.begin(),arr.end());
     vector<int> temp;
     solve(arr,0,temp);
     set<vector<int>>s(res.begin(),res.end());
     res.assign(s.begin(),s.end());
     return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends