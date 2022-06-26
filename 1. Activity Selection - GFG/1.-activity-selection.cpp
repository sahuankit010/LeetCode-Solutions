// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    
    static bool cmp(pair<int,int> p1, pair<int,int> p2){
        return p1.second<=p2.second;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
       vector<pair<int,int>> vs;
        for(int i=0;i<n;i++){
            vs.push_back({end[i],start[i]});
        }
        sort(vs.begin(),vs.end());
        int ans = 1;
        int last = vs[0].first;
        for(int i=1;i<n;i++){
            if(vs[i].second > last){
                ans++;
                last = vs[i].first;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends