class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         vector<int>temp;
//         int n = arr.size();
//         for(int i=0; i<n; i++){
//             temp.push_back(abs(x-arr[i]));
//         }
        
//         int mini = INT_MAX;
        
//         int idx;
        
//         for(int i=0; i<n; i++){
//             if(mini>temp[i]){
//                 idx = i;
//                 mini = temp[i];
//             }
//         }
//         vector<int> ans;
//         if(idx==0){
//             for(int i=0; i<k;i++){
//                 ans.push_back(arr[i]);
//             }
//             return ans;
//         } else if(idx==n){
//             for(int i=n-k; i<n; i++){
//                 ans.push_back(arr[i]);
//             }
//             return ans;
//         } else{
//             cout<<"sdsfd"<<endl<<idx;
//             int l=idx, r=idx+1;
//             int count = 0;
//             while(count<k){
//                 cout<<"HIn"<<endl;
//                 if(l>=0 && (abs(arr[l]-x)<=abs(arr[r]-x))){
//                     ans.push_back(ans[l]);
//                     l--;
                   
//                 } else if(r<n && (abs(arr[r]-x)<abs(arr[l]-x))){
//                     ans.push_back(ans[r]);
//                     r++;
                    
//                 }
//                 count++;
//             }
//             sort(ans.begin(), ans.end());
//             vector<int>res;
//             for(int i=0; i<k; i++){
//                 res.push_back(ans[i]);
//             }
//             return res;
//         }
        
        int n=arr.size();
        vector<int>ans;
        int start=0,end=n-1;
        while((end-start)>=k){
            if(abs(arr[start]-x) > abs(arr[end]-x)){
                start++;
            }
            else{
                end--;
            }
        } 
        for(int i=start;i<=end;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};